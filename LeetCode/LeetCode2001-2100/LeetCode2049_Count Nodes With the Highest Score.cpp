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

class Solution
{
 public:
    int countHighestScoreNodes(vector<int> &parents)
    {
        num_of_nodes_ = parents.size();
        adj_list_.resize(num_of_nodes_);
        for (int v = 1; v < num_of_nodes_; ++v)
            adj_list_[parents[v]].emplace_back(v);
        count_nodes(0);
        return scores_.crbegin()->second;
    }

    int count_nodes(int node_idx)
    {
        uint64_t product = 1, nodes = 0;
        /* Count each branch/children */
        for (const auto &v : adj_list_[node_idx])
        {
            int branch_nodes = count_nodes(v);
            nodes += branch_nodes;
            product *= branch_nodes;
        }
        product *= max(1ul, num_of_nodes_ - 1 - nodes);
        ++scores_[product];
        return nodes + 1;
    }

    int my_path_compression(vector<int> &parents)
    {
        /* Change definition: 
            ### If it's root node, the parent is itself ###
            First, change root's parent from -1 to 0 (itself) */
        parents[0] = 0;
        int max_score{1};
        vector<int> scores;
        for (int i = 0; i < num_of_nodes_; ++i)
        {
            scores.emplace_back(get_score(parents, i));
            max_score = max(max_score, scores[i]);
        }
        int num_of_max{0};
        for (const auto &s : scores)
            if (s == max_score)
                ++num_of_max;
        return num_of_max;
    }

 private:
    int num_of_nodes_;  // [1, 10^5]
    vector<vector<int>> adj_list_; 
    map<uint64_t, int> scores_;  // score ➡ the count of score
    /* Find with path compression */
    int find_parent(vector<int> &parents, int label_id)
    {
        if (parents[label_id] == label_id)
            return label_id;
        return parents[label_id] = find_parent(parents, parents[label_id]);
    }

    int get_score(vector<int> parents, int removed_target)
    {
        /* Set to my def: Removed node point to itself */
        parents[removed_target] = removed_target;
        for (int i = 0; i < num_of_nodes_; ++i)
        {
            if (parents[i] == removed_target)
                parents[i] = i;
        }

        /* Set to same parent (disjoint set trick) */
        for (int i = 0; i < parents.size(); ++i)
            find_parent(parents, i);

        /* node ➡ the number of nodes after removing it */
        vector<int> tree_nodes(num_of_nodes_, 0);
        for (int i = 0; i < num_of_nodes_; ++i)
            ++tree_nodes[parents[i]];
        int score{1};
        for (const auto &nodes : tree_nodes)
            if (nodes)
                score *= nodes;
        return score;
    }
};

int main(void)
{
    Solution sol;

    vector<int> parents{-1, 2, 0, 2, 0};
    sol.countHighestScoreNodes(parents);

    return 0;
}