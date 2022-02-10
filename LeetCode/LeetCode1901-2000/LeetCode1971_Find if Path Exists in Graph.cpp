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
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adj_list(n, vector<int>());
        for (const auto &e : edges)
        {
            adj_list[e[0]].emplace_back(e[1]);
            adj_list[e[1]].emplace_back(e[0]);
        }

        return my_BFS(n, adj_list, source, destination);
    }

 private:
    bool my_BFS(const int &n, const vector<vector<int>> &adj_list,
                const int &source, const int &destination)
    {
        vector<bool> visited(n, false);
        queue<int> bfs_q;

        bfs_q.emplace(source);
        while (!bfs_q.empty())
        {
            int vertex = bfs_q.front();
            bfs_q.pop();

            if (vertex == destination)
                return true;

            visited[vertex] = true;
            for (const auto &target : adj_list[vertex])
                if (!visited[target])
                    bfs_q.emplace(target);
        }
        return false;
    }
};

int main(void)
{

    return 0;
}
