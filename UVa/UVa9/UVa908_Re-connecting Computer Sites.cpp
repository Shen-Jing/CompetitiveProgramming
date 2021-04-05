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

enum Edge
{
    weight = 0,
    src_and_dst = 1
};

vector<int> parent;
vector<pair<int, pair<int, int>>> edges;

int find_root(int vertex)
{
    if (parent[vertex] == vertex) 
        return vertex;
    return (parent[vertex] = find_root(parent[vertex]));
}

int main(void)
{
    int num_sites, num_new_lines, num_original_lines;

    for (int k = 0; cin >> num_sites; ++k)
    {
        /* separated by a blank line */
        if (k != 0)
            cout << "\n";

        /* Initialization */
        edges.clear();
        edges.reserve(num_sites);
        parent.clear();
        parent.reserve(num_sites);

        for (int v = 0; v < num_sites; ++v)
        {
            parent.emplace_back(v);
        }

        int total{0};
        /* original set T */
        for (int e = 1; e <= num_sites - 1; ++e)
        {
            int tmp, cost;
            cin >> tmp >> tmp >> cost;
            total += cost;
        }
        cout << total << "\n";

        cin >> num_new_lines;
        for (int e = 0; e < num_new_lines; ++e)
        {
            int src, dst, weight;
            cin >> src >> dst >> weight;
            --src, --dst;

            edges.emplace_back(make_pair(weight, make_pair(src, dst)));
        }

        cin >> num_original_lines;
        for (int e = 0; e < num_original_lines; ++e)
        {
            int src, dst, weight;
            cin >> src >> dst >> weight;
            --src, --dst;

            edges.emplace_back(make_pair(weight, make_pair(src, dst)));
        }

        decltype(edges) minimum_spanning_tree;
        sort(edges.begin(), edges.end());
        total = 0;
        for (const auto &e : edges)
        {
            const auto &[src, dst] = get<Edge::src_and_dst>(e);
            if (find_root(src) != find_root(dst))
            {
                total += get<Edge::weight>(e);
                minimum_spanning_tree.emplace_back(e);
                parent[parent[dst]] = parent[src];
            }
        }
        cout << total << "\n";
    }

    return 0;
}