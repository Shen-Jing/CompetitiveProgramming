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
    int maximumScore(vector<int> &scores, vector<vector<int>> &edges)
    {
        int nodes = scores.size();
        // Convert edge list into adjacency list
        adj_list.assign(nodes, vector<int>{});
        for (const auto &edge : edges)
        {
            // undirected edge
            int u = edge[0], v = edge[1];
            adj_list[u].emplace_back(v);
            adj_list[v].emplace_back(u);
        }

        // Sort (based on their neighbor's score)
        for (int i = 0; i < nodes; ++i)
        {
            sort(adj_list[i].begin(), adj_list[i].end(), [&](int v1, int v2){
                                                            return scores[v1] > scores[v2];
                                                         });
        }

        int max_score{0};
        vector<pair<int, int>> u_pairs, v_pairs;
        for (const auto &edge : edges)
        {
            u_pairs.clear();
            v_pairs.clear();
            /* For each pair of vertices connected by the edge,
               try to consider them as the middle 2 vertices of a sequence */
            int mid_u = edge[0], mid_v = edge[1];
            retrieve_higher_neighbor_pairs(u_pairs, mid_u, mid_v);
            retrieve_higher_neighbor_pairs(v_pairs, mid_v, mid_u);
            
            max_score = max(max_score, get_score_from_vertices(scores, u_pairs, v_pairs, mid_u, mid_v));
        }

        if (!max_score)
            return -1;
        return max_score;
    }
 
 private:
    vector<vector<int>> adj_list;
    void retrieve_higher_neighbor_pairs(vector<pair<int, int>> &pairs,
                                        const int &src, const int &dst)
    {
        /* For these 2 vertices, retrieve 2 neighbors separately:
            - prefer higher score
            - exclude the middlepoint themselves (u, v) */
        int i{0};
        for (const auto &neighbor : adj_list[src])
        {
            if (neighbor == dst)
                continue;
            pairs.emplace_back(src, neighbor);
            ++i;
            if (i == 2)
                break;
        }
    }

    int get_score_from_vertices(const vector<int> &scores,
                                const vector<pair<int, int>> &u_pairs,
                                const vector<pair<int, int>> &v_pairs,
                                const int &mid_u,
                                const int &mid_v
                               )
    {
        int total_score{0}, score_up{0}, score_vp{0};
        if (u_pairs.empty() || v_pairs.empty())
            return 0;
        if (u_pairs.size() == 1)
        {
            const int &u_p1 = u_pairs[0].second;
            score_up = scores[u_p1];
            if (v_pairs.size() == 1)
            {
                const int &v_p1 = v_pairs[0].second;
                if (u_p1 == v_p1)
                    return 0;
                score_vp = scores[v_p1];
            }
            else
            {
              const int &v_p1 = v_pairs[0].second,
                        &v_p2 = v_pairs[1].second;
              if (u_p1 == v_p1)
                  score_vp = scores[v_p2];
              else
                  score_vp = scores[v_p1];
            }
        }
        else
        {
            const int &u_p1 = u_pairs[0].second,
                      &u_p2 = u_pairs[1].second;
            if (v_pairs.size() == 1)
            {
                const int &v_p1 = v_pairs[0].second;
                score_vp = scores[v_p1];
                if (u_p1 == v_p1)
                    score_up = scores[u_p2];
                else
                    score_up = scores[u_p1];
            }
            else
            {
                const int &u_p1 = u_pairs[0].second,
                          &u_p2 = u_pairs[1].second,
                          &v_p1 = v_pairs[0].second,
                          &v_p2 = v_pairs[1].second;
                if (u_p1 == v_p1)
                {
                    if (scores[u_p2] > scores[v_p2])
                    {
                        score_up = scores[u_p2];
                        score_vp = scores[v_p1];
                    }
                    else
                    {
                        score_up = scores[u_p1];
                        score_vp = scores[v_p2];
                    }
                }
                else
                {
                    score_up = scores[u_p1];
                    score_vp = scores[v_p1];
                }
            }
        }

        return score_up + scores[mid_u] +
               scores[mid_v] + score_vp;
    }
};

int main(void)
{
    vector<int> scores;
    vector<vector<int>> edges;;
    Solution sol;

    //scores.assign({5,2,9,8,4});
    //edges.assig({{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}});
    //sol.maximumScore(scores, edges);

    scores.assign({1,2,2,2,3});
    edges.assign({{2,0},{3,2},{3,4},{3,0},{4,1}});
    sol.maximumScore(scores, edges);

    return 0;
}