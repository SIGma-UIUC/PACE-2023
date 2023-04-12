#include <vector>
#include <unordered_set>
#include <string>
#include <fstream>
#include <iostream>

std::vector<std::unordered_set<int>>* parse_gr(std::string file){
    std::ifstream fin(file);
    std::vector<std::unordered_set<int>>* graph = new std::vector<std::unordered_set<int>>();
    std::vector<std::string> lines;

    for (std::string line; std::getline(fin, line);)
        lines.push_back(line);

    int n = 0;
    int m = 0;

    for(int i = 0; i < lines.size(); i++){
        if(lines[i][0] == 'c')
            continue;
        
        if(lines[i][0] == 'p'){
            int j = 2;
            while(lines[i][j] != ' ')
                j++;
            j++;
            while(lines[i][j] != ' '){
                n*=10;
                n+=lines[i][j]-'0';
                j++;
            }
            j++;
            while(j < lines[i].size()){
                m*=10;
                m+=lines[i][j]-'0';
                j++;
            }

            graph = new std::vector<std::unordered_set<int>>(n+1);
            continue;
        }

        int a = 0;
        int b = 0;

        int j = 0;
        while(lines[i][j] != ' '){
                a*=10;
                a+=lines[i][j]-'0';
                j++;
        }

        j++;
        while(j < lines[i].size()){
                b*=10;
                b+=lines[i][j]-'0';
                j++;
        }

        graph->at(a).insert(b);
        graph->at(b).insert(a);
    }

    return graph;
}

void print_graph(std::vector<std::unordered_set<int>> &graph){
    for(int node = 1; node < graph.size(); node++){
        std::cout << "Node: " << node << " - ";
        for(int edge : graph[node]){
            std::cout << edge << ", ";
        }
        std::cout << std::endl;
    }
}