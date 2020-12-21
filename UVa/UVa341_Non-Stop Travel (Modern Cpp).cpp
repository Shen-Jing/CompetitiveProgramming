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

#include <boost/range/irange.hpp>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int main(void)
{
    using EdgeProperty = boost::property<boost::edge_weight_t, int>;
    using Graph = boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property, EdgeProperty>;
    using Vertex = boost::graph_traits<Graph>::vertex_descriptor;
    using Edge = boost::graph_traits<Graph>::edge_descriptor;

    int NI;

    for (int kase = 1; ; ++kase)
    {
        Graph g;
        cin >> NI;
        if (!NI)
            break;
        
        /* build graph */
        vector<Vertex> vertices;
        vertices.reserve(NI);
        for (const auto &i : boost::irange(0, NI))
        {
            Vertex v = add_vertex(g);
            vertices.emplace_back(v);
        }

        for (int v = 0; v < NI; ++v)
        {
            int edges;
            cin >> edges;
            for (int e = 0; e < edges; ++e)
            {
                int neighbor, weight;
                cin >> neighbor >> weight;
                add_edge(vertices[v], vertices[neighbor - 1], weight, g);
            }
        }

        /* iterate edges */
        cout << "After reading input, edges are: \n";
        for (auto [e_it, e_end] = boost::edges(g); e_it != e_end; ++e_it)
        {
            cout << boost::source(*e_it, g) << " " << boost::target(*e_it, g) << "\n";
        }
        
        int src, dst;
        
        cin >> src >> dst;
        

        // vector for storing distance property
        vector<int> dist(boost::num_vertices(g));
        // get source vertex iterator
        auto vit_first = boost::vertices(g).first;
        // invoke variant 2 of Dijkstra's algorithm
        boost::dijkstra_shortest_paths(g, *(vit_first + (src - 1)), boost::distance_map(&dist[0]));
        cout << "Case " << kase << ": Path = " << src << " \n";
        cout << dist[*(vit_first + (dst - 1))] << " second delay\n\n";
    }

    return 0;
}