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

struct MinHeapNode
{
    int dst;
    int dist;  // shortest distance, not edge weight

    MinHeapNode(const int &dst, const int &dist) : dst(dst), dist(dist) { }
    bool operator < (const MinHeapNode &rhs) const
    {
        return this->dist > rhs.dist;
    }
};

/* fastest */
void set_Dijsktra_queue()
{

}

int main(void)
{
    int NI;  // the number of intersections

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
        --src, --dst;
        
        /* source vertex → all destination */
        auto shortest_distance = vector<int>(NI, numeric_limits<int>::max() / 2);
        auto path_from = vector<int>(NI, -1);

        shortest_distance[src] = 0;
        priority_queue<MinHeapNode> shortest_queue;
        shortest_queue.push((MinHeapNode){src, 0});

        while (!shortest_queue.empty())
        {
            auto cur_vertex = shortest_queue.top();
            shortest_queue.pop();
            
            /* if done[cur_vertex] (have updated/relaxed to shortest distance) */
            if (cur_vertex.dist != shortest_distance[cur_vertex.dst])
                continue;
            // done[cur_vertex.dst] = true;

            for (int e = 0; e < adj_list[cur_vertex.dst].size(); ++e)
            {
                int neighbor = get<Edge::neighbor>(adj_list[cur_vertex.dst][e]);
                int weight = get<Edge::weight>(adj_list[cur_vertex.dst][e]);

                if (shortest_distance[neighbor] > shortest_distance[cur_vertex.dst] + weight)
                {
                    shortest_distance[neighbor] = shortest_distance[cur_vertex.dst] + weight;
                    path_from[neighbor] = cur_vertex.dst;
                    shortest_queue.push((MinHeapNode){neighbor, shortest_distance[neighbor]});  // update priority
                }
            }
        }

        cout << "Case " << kase << ": Path = " << src << " ";
        auto ans = stack<int>();
        int next = dst;
        while (path_from[next] != src)
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
        cout << shortest_distance[dst] << " second delay\n";
    }

    return 0;
}