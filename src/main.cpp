#include "parser.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

int main(int argc, char *argv[]){
    std::string input = argv[0];
    std::vector<std::unordered_set<int>>* graph = parse_gr(input);
}