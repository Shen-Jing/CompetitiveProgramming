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
#include <span>
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

class Solution
{
 public:
    /* vertex labels: 1 based */
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pair<int, int>>> edge_list(n, vector<pair<int, int>>());
        for (int e = 0; e < times.size(); ++e)
        {
            /* Source, Destination, Weight */
            int u = times[e][0] - 1, v = times[e][1] - 1, 
                w = times[e][2];
            auto edge = make_pair(v, w);
            edge_list[u].emplace_back(edge);
        }
        return dijkstra(edge_list, n, k - 1);
    }

 private:
    /* vertex labels: 0 based */
    int dijkstra(vector<vector<pair<int, int>>> &edge_list, const int &n, const int &src)
    {
        vector<int> dist(n, numeric_limits<int>::max());
        dist[src] = 0;

        /* {dist, target} */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dist_q;
        dist_q.emplace(0, src);
        while (!dist_q.empty())
        {
            auto [d, u] = dist_q.top();
            dist_q.pop();
            if (d > dist[u])  // Lazy Deletion
                continue;
            for (const auto &e : edge_list[u])
            {
                int v = e.first, w = e.second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    dist_q.emplace(dist[v], v);
                }
            }
        }

        int max_dist = numeric_limits<int>::min();
        for (const auto &d : dist)
        {
            if (d == numeric_limits<int>::max())
                return -1;
            max_dist = max(max_dist, d);
        }
        return max_dist;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> times;

    times = {{2,1,1}, {2,3,1}, {3,4,1}};
    sol.networkDelayTime(times, 4, 2);

    return 0;
}