#include "gtest/gtest.h"
#include "../src/parser.hpp"

#include <unordered_set>
#include <vector>

TEST(TestInput, Testing){
    std::vector<std::unordered_set<int>> expected(6);
    expected[1].insert(5);
    expected[5].insert(1);
    expected[1].insert(4);
    expected[4].insert(1);
    expected[1].insert(3);
    expected[3].insert(1);

    std::vector<std::unordered_set<int>>* test = parse_gr("samples/standard.gr");
    EXPECT_EQ(expected, *test);
}