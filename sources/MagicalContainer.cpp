#include "MagicalContainer.hpp"
#include <vector>
using namespace std;
using namespace ariel;


//----------------------------- MagicalContainer class -----------------------------//
MagicalContainer::MagicalContainer() {}

MagicalContainer::~MagicalContainer() {}

void MagicalContainer::addElement(int element) {}

void MagicalContainer::removeElement(int element) {}

int MagicalContainer::size() const {
    return elements.size();
}

std::vector<int> MagicalContainer::getElements() const{
    return elements;
}




//----------------------------- AscendingIterator class -----------------------------//

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container_, int index_)
    : container(container_), index(index_) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
    : container(other.container), index(other.index) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& other)
    : container(other), index(0) {}

MagicalContainer::AscendingIterator::~AscendingIterator() {}

//--- Overlaoding Operators ---//
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return &container == &other.container && index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return index > other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return index < other.index;
}

int MagicalContainer::AscendingIterator::operator*() const {
    return container.getElements().at((vector<int>::size_type)index);
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    index++;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    return AscendingIterator(container, 0);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
    return AscendingIterator(container, container.size());
}




//----------------------------- SideCrossIterator class -----------------------------//

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container_, int index_, bool fromStart_)
    : container(container_), index(index_), fromStart(fromStart_) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container), index(other.index), fromStart(other.fromStart) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& other)
    : container(other), index(0), fromStart(true) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}


//--- Overloading Operators ---//
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return index == other.index && fromStart == other.fromStart;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return index > other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return index < other.index;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return 0;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
    return SideCrossIterator(container, 0, true);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
    return SideCrossIterator(container, container.size(), false);
}




//----------------------------- PrimeIterator class -----------------------------//
MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container_, int index_)
    : container(container_), index(index_) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : container(other.container), index(other.index) {}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& other)
    : container(other), index(0) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}


//--- Overlaoding Operators ---//
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return &container == &other.container && index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return index > other.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return index < other.index;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return 0;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    return *this;
}

bool isPrime(int number) {
    if (number <= 1)
        return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0)
            return false;
    }
    return true;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
    return PrimeIterator(container, 0);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
    return PrimeIterator(container, container.size());
}
