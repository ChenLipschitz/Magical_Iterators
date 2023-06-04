#include <iostream>
#include "sources/MagicalContainer.hpp"
#include "doctest.h"
#include <vector>

using namespace ariel;

TEST_CASE("MagicalContainer methods"){
    MagicalContainer magic_container;
    SUBCASE("Check size method"){
        CHECK(magic_container.size() == 0);
        magic_container.addElement(32);
        magic_container.addElement(43);
        magic_container.addElement(32);
        magic_container.addElement(44);
        CHECK_NE(magic_container.size(), 0);
        CHECK(magic_container.size() == 4);
        magic_container.removeElement(32);
        CHECK(magic_container.size() != 4);
        CHECK(magic_container.size() == 3);
        magic_container.removeElement(43);
        magic_container.removeElement(32);
        magic_container.removeElement(44);        
    }

    SUBCASE("Check addElement method"){
        CHECK_NOTHROW(magic_container.addElement(1));
        CHECK(magic_container.size() == 1);
    }

    SUBCASE("Check removeElement method"){
        CHECK_THROWS(magic_container.removeElement(1));
        magic_container.addElement(1);
        CHECK_NOTHROW(magic_container.removeElement(1));
        magic_container.addElement(2);
        magic_container.addElement(3);
        magic_container.removeElement(4);
        CHECK_THROWS(magic_container.removeElement(4));
        CHECK( magic_container.size() == 2);
        magic_container.removeElement(2);
        magic_container.removeElement(3);
        CHECK( magic_container.size() == 0);
    }

    SUBCASE("Check getElements method"){
        CHECK(magic_container.getElements().size() == 0);
        CHECK_NOTHROW(magic_container.getElements());
    }

}

TEST_CASE("AscendingIterator methods"){
    MagicalContainer magic_container;
    magic_container.addElement(1);
    magic_container.addElement(3);
    magic_container.addElement(4);
    magic_container.addElement(5);
    magic_container.addElement(2);

    MagicalContainer::AscendingIterator asItr(magic_container);
    auto itr = asItr.begin();
    
    SUBCASE("Check iteration in ascending order") {
        vector<int> expected_elements{1, 2, 3, 4, 5};
        vector<int> actual_elements;

        // Iterate over the elements and store them in the actual_elements vector
        while (asItr != asItr.end()) {
            actual_elements.push_back(*asItr);
            ++asItr;
        }

        CHECK(actual_elements == expected_elements);
    }

    SUBCASE("Check iterator comparison operators") {
        auto end = asItr.end();

        CHECK(itr == itr);
        CHECK(end == end);
        CHECK(itr != end);
        CHECK(end != itr);
        CHECK(itr < end);
        CHECK(end > itr);
    }

    SUBCASE("Check iterator dereference operator") {
        CHECK(*itr == 1);
    }

    SUBCASE("Check iterator increment operator") {
        ++itr;
        CHECK(*itr == 2);

        ++itr;
        CHECK(*itr == 3);
    }
}

TEST_CASE("SideCrossIterator Test") {
    MagicalContainer magic_container;
    magic_container.addElement(4);
    magic_container.addElement(8);
    magic_container.addElement(12);

    MagicalContainer::SideCrossIterator s_cross_iterator(magic_container);
    auto begin_iterator = s_cross_iterator.begin();

    SUBCASE("begin() and end()") {
        auto end_iterator = s_cross_iterator.end();
        CHECK(*begin_iterator == 4);
        CHECK(begin_iterator != end_iterator);
        ++begin_iterator;
        CHECK(*begin_iterator == 12);
        ++begin_iterator;
        CHECK(begin_iterator == end_iterator);
    }

    SUBCASE("Check iterator increment operator") {
        ++begin_iterator;
        CHECK(*begin_iterator == 12);
        ++begin_iterator;
        CHECK(begin_iterator == s_cross_iterator.end());

        // Test incrementing beyond the end of the iterator
        CHECK_THROWS(++begin_iterator);
    }

    SUBCASE("Check iterator comparison operators") {
        auto begin_iterator2 = s_cross_iterator.begin();
        // Test equality and inequality operators
        CHECK(begin_iterator == begin_iterator2);
        CHECK_FALSE(begin_iterator != begin_iterator2);

        // Increment iterator2 and test inequality
        ++begin_iterator2;
        CHECK(begin_iterator != begin_iterator2);
        CHECK_FALSE(begin_iterator == begin_iterator2);

        // Reset iterator2
        begin_iterator2 = s_cross_iterator.begin();

        CHECK_FALSE(begin_iterator > begin_iterator2);
        CHECK_FALSE(begin_iterator2 > begin_iterator);
        CHECK_FALSE(begin_iterator < begin_iterator2);
        CHECK_FALSE(begin_iterator2 < begin_iterator);

        // Increment iterator2 and test comparison
        ++begin_iterator2;
        CHECK(begin_iterator2 > begin_iterator);
        CHECK_FALSE(begin_iterator > begin_iterator2);
        CHECK(begin_iterator < begin_iterator2);
        CHECK_FALSE(begin_iterator2 < begin_iterator);
    }

    SUBCASE("Check iterator dereference operator") {
        CHECK(*begin_iterator == 4);
        ++begin_iterator;
        CHECK(*begin_iterator == 12);
    }
}






 