#include "gtest/gtest.h"
#include "../src/parser.hpp"

#include <unordered_set>
#include <vector>

TEST(TestInput, TestStandard){
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

TEST(TestInput, TestComments){
    std::vector<std::unordered_set<int>> expected(13);
    expected[1].insert(11);
    expected[11].insert(1);
    expected[1].insert(10);
    expected[10].insert(1);
    expected[1].insert(9);
    expected[9].insert(1);
    expected[11].insert(12);
    expected[12].insert(11);
    expected[10].insert(11);
    expected[11].insert(10);
    expected[5].insert(6);
    expected[6].insert(5);
    expected[4].insert(5);
    expected[5].insert(4);
    expected[3].insert(4);
    expected[4].insert(3);
    expected[1].insert(2);
    expected[2].insert(1);
    expected[3].insert(7);
    expected[7].insert(3);

    std::vector<std::unordered_set<int>>* test = parse_gr("samples/comments.gr");
    EXPECT_EQ(expected, *test);
}