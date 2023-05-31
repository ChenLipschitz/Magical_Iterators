#pragma once

#include <vector>
#include <iterator>

class MagicalContainer {
private:
    std::vector<int> elements;

public:
    MagicalContainer();
    ~MagicalContainer();
    void addElement(int element);
    void removeElement(int element);
    int getSize() const;


    class AscendingIterator {
    private:
        const MagicalContainer& container;
        int index;

    public:
        AscendingIterator(const MagicalContainer& container, int index);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator();

        // overlaoding operators
        AscendingIterator& operator=(const AscendingIterator& other);
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        int operator*() const;
        AscendingIterator& operator++();

        // Get the iterator pointing to... element
        static AscendingIterator begin(const MagicalContainer& container);
        static AscendingIterator end(const MagicalContainer& container);
    };


    // SideCrossIterator class
    class SideCrossIterator {
    private:
        const MagicalContainer& container;
        int index;
        bool fromStart;

    public:
        SideCrossIterator(const MagicalContainer& container, int index, bool fromStart);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator();

        // overloading operator
        SideCrossIterator& operator=(const SideCrossIterator& other);
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        int operator*() const;
        SideCrossIterator& operator++();

        // Get the iterator pointing to... element
        static SideCrossIterator begin(const MagicalContainer& container);
        static SideCrossIterator end(const MagicalContainer& container);
    };


    // PrimeIterator class
    class PrimeIterator {
    private:
        const MagicalContainer& container;
        int index;

    public:
        PrimeIterator(const MagicalContainer& container, int index);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator();

        // overloading operator
        PrimeIterator& operator=(const PrimeIterator& other);
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        int operator*() const;
        PrimeIterator& operator++();

        // Get the iterator pointing to... element
        static PrimeIterator begin(const MagicalContainer& container);
        static PrimeIterator end(const MagicalContainer& container);

        // Helper function to check if a number is prime
        bool isPrime(int number) const;
    };
};
