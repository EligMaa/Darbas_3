#define CATCH_CONFIG_MAIN
#include"catch.hpp"
#include "VEKTORIUS.h"

TEST_CASE(" push_back ") {

    VEKTORIUS<int> v = {1};

    v.push_back(2);
    v.push_back(3);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
}

TEST_CASE(" pop_back ") {

    VEKTORIUS<int> v = {1,2,3};
    size_t dydis = v.size();

    v.pop_back();
    REQUIRE(v.size() == dydis - 1);

    for (size_t i = 0; i < v.size(); ++i) {
        REQUIRE(v[i] == i + 1);
    }

}

TEST_CASE(" erase ") {
    
    VEKTORIUS<int> v = {1,2,3};
    v.erase(v.begin()+1);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 3);
}

TEST_CASE(" insert ") {
    
    VEKTORIUS<int> v = {1,2,3};
    v.insert(v.begin(), 15);
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 15);
    REQUIRE(v[1] == 1);
    REQUIRE(v[2] == 2);
    REQUIRE(v[3] == 3);

}
