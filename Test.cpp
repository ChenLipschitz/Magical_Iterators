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
        CHECK_THROWS(magic_container.addElement(1));
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


    SUBCASE("Check iteration in ascending order") {
        vector<int> expected_elements{1, 2, 3, 4, 5};
        vector<int> actual_elements;

        MagicalContainer::AscendingIterator asItr(magic_container);

        // Iterate over the elements and store them in the actual_elements vector
        while (asItr != asItr.end()) {
            actual_elements.push_back(*asItr);
            ++asItr;
        }

        CHECK(actual_elements == expected_elements);
    }

    SUBCASE("Check iterator comparison operators") {
        MagicalContainer::AscendingIterator asItr(magic_container);
        auto itr = asItr.begin();
        auto end = asItr.end();

        CHECK(itr == itr);
        CHECK(end == end);
        CHECK(itr != end);
        CHECK(end != itr);
        CHECK(itr < end);
        CHECK(end > itr);
    }

    SUBCASE("Check iterator dereference operator") {
        MagicalContainer::AscendingIterator asItr(magic_container);
        auto itr = asItr.begin();
        CHECK(*itr == 1);
    }

    SUBCASE("Check iterator increment operator") {
        MagicalContainer::AscendingIterator asItr(magic_container);
        auto itr = asItr.begin();

        ++itr;
        CHECK(*itr == 2);

        ++itr;
        CHECK(*itr == 3);
    }
}








 