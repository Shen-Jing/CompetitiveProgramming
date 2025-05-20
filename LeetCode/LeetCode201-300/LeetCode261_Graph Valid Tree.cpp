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
        n_ = n;
        visited.assign(n, false);
        return DFS_stack(edges);
        return DFS(0, 0, edges);
    }

 private:
    int n_;
    vector<bool> visited;
    bool DFS(int parent, int source, vector<vector<int>> &edges)
    {
        for (const auto &neighbor : edges[source])
        {
            if (neighbor == parent)
                continue;
            if (visited[neighbor])
                return false;
            visited[neighbor] = true;
            DFS(source, neighbor, edges);
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