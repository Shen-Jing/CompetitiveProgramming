#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <tuple>
#include <type_traits>
#include <utility>
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

class Solution
{
 public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj_list(n, vector<int>());
        /* Preprocessing */
        for (const auto &edge : edges)
        {
            adj_list[edge[0]].emplace_back(edge[1]);
            adj_list[edge[1]].emplace_back(edge[0]);
        }
        return my_DFS(n, adj_list);
    }
    
 private: 
    int min_height_{numeric_limits<int>::max()};

    vector<int> my_DFS(int n, vector<vector<int>>& adj_list)
    {
        vector<int> heights, MHT_roots;
        for (int node_i = 0; node_i < n; ++node_i)
        {
            vector<bool> visited(n, false);
            int height{0};
            heights.emplace_back(DFS(adj_list, visited, node_i, 0, height));
            min_height_ = min(min_height_, height);
        }
        for (int node_i = 0; node_i < n; ++node_i)
            if (heights[node_i] == min_height_)
                MHT_roots.emplace_back(node_i);
        return MHT_roots;
    }

    int DFS(const vector<vector<int>> &edges, vector<bool> &visited,
            const int &node, int path_length, int &height)
    {
        if (visited[node])
            return 0;
        visited[node] = true;
        for (const auto &neighbor : edges[node])
        {
            DFS(edges, visited, neighbor, path_length + 1, height);
        }
        height = max(height, path_length);
        return height;
    }
};

int main(void)
{

    return 0;
}