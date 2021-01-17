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

vector<string> beverages;
map<string, int> beverage2id;
vector<vector<int>> edges;
vector<int> in_degree;
vector<int> ans;

/* Kahn's Algorithm */
void topological_sort()
{
    priority_queue<int, vector<int>, greater<int>> vertex_pq;
    for (int v = 0; v < in_degree.size(); ++v)
        if (!in_degree[v])
            vertex_pq.push(v);

    while (!vertex_pq.empty())
    {
        auto cur_vertex = vertex_pq.top();
        vertex_pq.pop();
        /* traverse all neighbors */
        for (const auto &dst : edges[cur_vertex])
        {
            --in_degree[dst];
            if (!in_degree[dst])
                vertex_pq.push(dst);
        }
        ans.emplace_back(cur_vertex);
    }
}

int main(void)
{
    int num_of_beverages;

    for (int kase = 1; cin >> num_of_beverages; ++kase) {
        /* Initialization */
        beverages.clear();
        beverage2id.clear();
        ans.clear();
        in_degree.assign(num_of_beverages, 0);
        for (int b_id = 0; b_id < num_of_beverages; ++b_id)
        {
            string name;
            cin >> name;
            beverages.emplace_back(name);
            beverage2id[name] = b_id;
        }
        
        int num_of_edges;
        cin >> num_of_edges;
        edges.assign(num_of_beverages, vector<int>());
        for (int e = 0; e < num_of_edges; ++e)
        {
            string src, dst;
            cin >> src >> dst;
            edges[beverage2id[src]].emplace_back(beverage2id[dst]);
            ++in_degree[beverage2id[dst]];
        }
        cin.ignore(10, '\n');
        
        cout << "Case #" << kase << ": Dilbert should drink beverages in this order: ";
        topological_sort();
        for (auto it = ans.cbegin(); it != ans.cend(); ++it)
        {
            cout << beverages[*it];
            if (it != ans.cend() - 1)
                cout << " ";
        }
        cout << ".\n\n";
    }

    return 0;
}