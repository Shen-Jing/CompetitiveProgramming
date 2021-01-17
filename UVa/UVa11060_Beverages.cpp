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

enum Status
{
    unvisited,
    visiting,
    visited
};

vector<string> beverages;
map<string, int> beverage2id;
vector<vector<int>> edges;
vector<int> vertex_status;
vector<int> ans;

void dfs(int src)
{
    /* traverse all neighbors */
    vertex_status[src] = Status::visited;
    for (const auto &dst : edges[src])
    {
        if (vertex_status[dst] == Status::unvisited)
            dfs(dst);
    }
    ans.emplace_back(src);
}

void topological_sort()
{
    for (int i = 0; i < vertex_status.size(); ++i)
    {
        if (vertex_status[i] == Status::unvisited)
            dfs(i);
    }
}

int main(void)
{
    int num_of_beverages;

    for (int kase = 1; cin >> num_of_beverages; ++kase)
    {
        if (kase != 1)
            cout << "\n";
        beverages.clear();
        beverage2id.clear();
        ans.clear();
        vertex_status.assign(num_of_beverages, Status::unvisited);
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
        }
        cin.ignore(10, '\n');
        
        cout << "Case #" << kase << ": Dilbert should drink beverages in this order: ";
        topological_sort();
        for (auto it = ans.crbegin(); it != ans.crend(); ++it)
        {
            cout << beverages[*it];
            if (it != ans.crend() - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}