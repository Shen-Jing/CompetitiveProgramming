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

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

struct Edge
{
    int src, dst, weight;
    Edge(int s = 0, int d = 0, int w = 0) : src(s), dst(d), weight(w) {}
    bool operator<(const Edge &e) const
    {
        return weight < e.weight;
    }
};

int find_root(vector<int> &root, int v)
{
    return (root[v] == v) ? v : (root[v] = find_root(root, root[v]));
}

bool Kruskal(const vector<Edge> edges, vector<int> root, const int first, const int last)
{
    for (int e = first; e < last; ++e)
    {
        int src_root = find_root(root, edges[e].src),
            dst_root = find_root(root, edges[e].dst);
        if (src_root != dst_root)
            root[src_root] = dst_root;
        else
            return false;    
    }
    return true;
}

int main(void)
{
    int num_of_vertices, num_of_edges;
    vector<Edge> edges;
    while (cin >> num_of_vertices >> num_of_edges)
    {
        if (!num_of_vertices && !num_of_edges)
            break;
        edges.clear();
        edges.reserve(num_of_edges);
        for (int e = 0; e < num_of_edges; ++e)
        {
            int src, dst, weight;
            cin >> src >> dst >> weight;
            edges.emplace_back(Edge(src, dst, weight));
        }
        sort(edges.begin(), edges.end());

        vector<int> root;
        root.reserve(num_of_vertices + 1);
        for (int v = 0; v <= num_of_vertices; ++v)
            root.emplace_back(v);
        int slimness, smallest_slimness = numeric_limits<int>::max();
        for (int e = 0, last_e = e + num_of_vertices - 1;
                 last_e <= num_of_edges;
                 ++e, last_e = e + num_of_vertices - 1)
        {
            if (Kruskal(edges, root, e, last_e))
            {
                slimness = edges[last_e - 1].weight - edges[e].weight;
                smallest_slimness = min(smallest_slimness, slimness);
            }
        }
        cout << ((smallest_slimness == numeric_limits<int>::max()) ? -1 : smallest_slimness) << "\n";
    }
    return 0;
}