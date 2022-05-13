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
#include <regex>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

void bicolor_all(const vector<vector<int>> &edge_list, const int &num_nodes)
{
    /* color: N (None), Red, Blue 
                -1, 0, 1 */
    vector<char> node_colors(num_nodes, 'N');
    queue<int> Q;
    Q.emplace(0);
    node_colors[0] = 'R';
    while (!Q.empty())
    {
        int cur_node = Q.front();
        Q.pop();
        char nxt_color = (node_colors[cur_node] == 'R') ? 'B' : 'R';
        for (const auto &neighbor : edge_list[cur_node])
        {
            if (node_colors[neighbor] != 'N')
            {
                if (node_colors[neighbor] == node_colors[cur_node])
                {
                    cout << "NOT BICOLORABLE.\n";
                    return;
                }
            }
            else
            {
                node_colors[neighbor] = nxt_color;
                Q.emplace(neighbor);
            }
        }
    }
    cout << "BICOLORABLE.\n";
}

int main(void)
{
    int num_nodes, num_edges;
    vector<vector<int>> edge_list;

    while (cin >> num_nodes && num_nodes != 0)
    {
        cin >> num_edges;

        edge_list.clear();
        edge_list.resize(num_nodes);
        int u, v;
        for (int e = 0; e < num_edges; ++e)
        {
            cin >> u >> v;
            edge_list[u].emplace_back(v);
            edge_list[v].emplace_back(u);
        }
        bicolor_all(edge_list, num_nodes);
    }
    return 0;
}