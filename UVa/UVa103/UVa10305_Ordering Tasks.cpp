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

enum class VertexStatus
{
  kNotVisited = -1,
  kVisiting = 0,
  kVisited = 1,
};

vector<int> tasks;
vector<VertexStatus> all_vertex_status;

void topological_sort(const vector<vector<pair<int, int>>> &edge_lists, int vertex)
{
    all_vertex_status[vertex] = VertexStatus::kVisiting;
    for (const auto e : edge_lists[vertex])
    {
        const auto &dst = e.first;
        if (all_vertex_status[dst] == VertexStatus::kNotVisited)
            topological_sort(edge_lists, dst);
    }
    all_vertex_status[vertex] = VertexStatus::kVisited;
    tasks.emplace_back(vertex);
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
        tasks.clear();
        all_vertex_status.clear();
        all_vertex_status.assign(num_tasks, VertexStatus::kNotVisited);
        
        /* Data */
        auto edge_lists = vector<vector<pair<int, int>>>(num_tasks, vector<pair<int, int>>());
        for (int e = 0; e < num_edges; ++e)
        {
            int src, dst;
            cin >> src >> dst;
            edge_lists[src - 1].emplace_back(make_pair(dst - 1, 1));
        }

        for (int src = 0; src < num_tasks; ++src)
            if (all_vertex_status[src] == VertexStatus::kNotVisited)
                topological_sort(edge_lists, src);

        for (auto it = tasks.crbegin(); it != tasks.crend(); ++it)
        {
            cout << (*it + 1);
            if (it != tasks.crend() - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}