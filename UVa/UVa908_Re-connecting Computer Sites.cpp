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
    neighbor = 0,
    weight = 1,
};

vector<vector<pair<int, int>>> edge_list;

void union_set(int father, int other)
{

}

int main(void)
{
    int num_sites, num_new_lines, num_original_lines;

    while (cin >> num_sites)
    {
        edge_list.clear();
        edge_list.assign(num_sites, vector<pair<int, int>>());

        int total{0};
        /* original set T */
        edge_list[0].reserve(num_sites - 1);
        for (int e = 1; e <= num_sites - 1; ++e)
        {
            int tmp, cost;
            cin >> tmp >> tmp >> cost;
            total += cost;

            /* reserve vector in passing */
            edge_list[e].reserve(num_sites - 1);
        }
        cout << total << "\n";

        cin >> num_new_lines;
        for (int e = 0; e < num_new_lines; ++e)
        {
            int src, dst, weight;
            cin >> src >> dst >> weight;
            --src, --dst;

            edge_list[src].emplace_back(make_pair(dst, weight));
            edge_list[dst].emplace_back(make_pair(src, weight));
        }

        cin >> num_original_lines;
        for (int e = 0; e < num_new_lines; ++e)
        {
            int src, dst, weight;
            cin >> src >> dst >> weight;
            --src, --dst;

            edge_list[src].emplace_back(make_pair(dst, weight));
            edge_list[dst].emplace_back(make_pair(src, weight));
        }

        decltype(edge_list) MST;

        /* separated by a blank line */
        cout << "\n";
    }

    return 0;
}