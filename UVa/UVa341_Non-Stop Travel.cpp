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

enum Edge { neighbor = 0, weight = 1 };

int get_weight(const vector<vector<pair<int, int>>> &adj_list, const int &from, const int &to)
{
    for (int e = 0; e < adj_list[from].size(); ++e)
    {
        int neighbor = get<Edge::neighbor>(adj_list[from][e]);
        if (to == neighbor)
          return get<Edge::weight>(adj_list[from][e]);
    }
    /* not found */
    return -1;
}

int main(void)
{
    int NI;

    for (int kase = 1; ; ++kase)
    {
        cin >> NI;
        if (!NI)
            break;
        
        auto adj_list = vector<vector<pair<int, int>> >(NI, vector<pair<int, int>>());

        for (int v = 0; v < NI; ++v)
        {
            int edges;
            cin >> edges;
            for (int e = 0; e < edges; ++e)
            {
                int neighbor, weight;
                cin >> neighbor >> weight;
                auto edge = pair<int, int>(neighbor - 1, weight);
                adj_list[v].emplace_back(edge);
            }
        }
        
        int src, dst;
        
        cin >> src >> dst;
        
        /* source vertex → all destination */
        auto shortest_distance = vector<int>(NI, numeric_limits<int>::max());
        auto path_from = vector<int>(NI, -1);
        shortest_distance[src - 1] = 0;
        for (int e = 0; e < adj_list[src - 1].size(); ++e)
        {
            int neighbor = get<Edge::neighbor>(adj_list[src - 1][e]);
            shortest_distance[neighbor] = get<Edge::weight>(adj_list[src - 1][e]);
            path_from[neighbor] = src - 1;
        }

        /* can reach new vertex */
        for (int v = 0; v < NI; ++v)
        {
            /* relax the shortest distance of all vertex (destination) */
            if (src - 1 == v)
                continue;
            for (int t = 0; t < NI; ++t)
            {
                int weight = get_weight(adj_list, v, t);
                if (weight != -1)
                    if (shortest_distance[t] > shortest_distance[v] + weight)
                    {
                        shortest_distance[t] = shortest_distance[v] + weight;
                        path_from[t] = v;
                    }
            }
        }

        cout << "Case " << kase << ": Path = " << src << " ";
        auto ans = stack<int>();
        int next = dst - 1;
        while (path_from[next] != src - 1)
        {
            ans.push(path_from[next] + 1);
            next = path_from[next];
        }
        while (!ans.empty())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << dst << "; ";
        cout << shortest_distance[dst - 1] << " second delay\n";
    }

    return 0;
}