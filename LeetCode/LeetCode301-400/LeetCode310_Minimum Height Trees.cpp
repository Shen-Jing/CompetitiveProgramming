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
        adj_list_.assign(n, vector<int>());
        /* Preprocessing */
        for (const auto &edge : edges)
        {
            adj_list_[edge[0]].emplace_back(edge[1]);
            adj_list_[edge[1]].emplace_back(edge[0]);
        }
        return brute_force_by_DFS(n, adj_list_);
    }
    
 private: 
    int min_height_{numeric_limits<int>::max()};
    vector<vector<int>> adj_list_;

    vector<int> brute_force_by_DFS(int n, vector<vector<int>>& adj_list)
    {
        vector<int> MHT_roots;
        /* Brute force:
            Consider each one of the nodes as root
            and calculating the height of the tree */
        min_height_ = n;
        for (int node_i = 0; node_i < n; ++node_i)
        {
            vector<bool> visited(n, false);
            int height = DFS(adj_list, visited, node_i);
            if (height < min_height_)
            {
                /* Get ans by 1 pass */
                MHT_roots.clear();
                min_height_ = height;
            }
            if (height == min_height_)
                MHT_roots.emplace_back(node_i);
        }
        return MHT_roots;
    }

    int DFS(const vector<vector<int>> &edges, vector<bool> &visited,
            const int &node)
    {
        int height{0};
        visited[node] = true;
        for (const auto &neighbor : edges[node])
        {
            if (!visited[neighbor])
                height = max(height,
                             1 + DFS(edges, visited, neighbor));
        }
        return height;
    }
};

int main(void)
{

    return 0;
}