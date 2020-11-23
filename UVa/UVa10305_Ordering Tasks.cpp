#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <type_traits>
#include <utility>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int t;
vector<int> tasks;
vector<bool> visited;

void topological_sort(const vector<vector<pair<int, int>>> &edge_lists, int vertex)
{
    visited[vertex] = true;
    tasks.emplace_back(vertex);
    for (const auto e : edge_lists[vertex])
    {
        const auto &dst = e.first;
        if (!visited[dst])
            topological_sort(edge_lists, dst);
    }
}

int main(void)
{
    int num_tasks, num_edges;

    tasks.reserve(100);
    while (cin >> num_tasks >> num_edges)
    {
        if (!num_tasks)
            break;

        /* Initialization */
        t = 0;
        tasks.clear();
        visited.clear();
        visited.assign(num_tasks, false);
        
        /* Data */
        auto edge_lists = vector<vector<pair<int, int>>>(num_tasks, vector<pair<int, int>>());
        for (int e = 0; e < num_edges; ++e)
        {
            int src, dst;
            cin >> src >> dst;
            edge_lists[src - 1].emplace_back(make_pair(dst - 1, 1));
        }

        for (int src = 0; src < num_tasks; ++src)
            if (!visited[src])
                topological_sort(edge_lists, src);

        for (auto t : tasks)
            cout << (t + 1) << " ";
        cout << "\n";
    }

    return 0;
}