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
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (n - 1 != edges.size())
            return false;
        visited.assign(n, false);
        /// Transform to adjacency list
        adj_list.assign(n, vector<int>());
        for (const auto &e : edges)
        {
            int source = e[0],
                target = e[1];
            adj_list[source].emplace_back(target);
            adj_list[target].emplace_back(source);
        }

        // return DFS_stack(edges);
        bool noCycle = noCycle_DFS(0, 0);
        for (const auto &vis : visited)
        {
            if (!vis)
                return false;
        }
        return noCycle;
    }

 private:
    vector<bool> visited;
    vector<vector<int>> adj_list;
    /// @return false for containing the cycle (not a valid tree)
    bool noCycle_DFS(int parent, int source)
    {
        visited[source] = true;
        for (const auto &neighbor : adj_list[source])
        {
            if (neighbor == parent)
                continue;
            if (visited[neighbor] || !noCycle_DFS(source, neighbor))
                return false;
        }
        return true;
    }

    bool DFS_stack(vector<vector<int>> &edges)
    {
        stack<int> traversal_stack;
        traversal_stack.push(0);
        while (!traversal_stack.empty())
        {
            int node = traversal_stack.top();
            traversal_stack.pop();
            for (const auto &neighbor : edges[node])
            {
                traversal_stack.push(neighbor);
                if (visited[neighbor])
                    return false;
                visited[neighbor] = true;
            }
        }
        return true;
    }
};

int main(void)
{

    return 0;
}