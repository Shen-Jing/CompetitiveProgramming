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
#include "utils.hpp"

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<int, vector<int>> graph;
        set_graph_from_tree(root, graph);

        /* Use BFS to get the distance with the farthest node */
        int dist = 0;
        unordered_map<int, bool> visited;
        queue<int> tree_q;
        visited[start] = true;
        tree_q.emplace(start);
        while (!tree_q.empty())
        {
            ++dist;
            int cur_sz = tree_q.size();
            for (int i = 0; i < cur_sz; ++i)
            {
                int cur_vertex = tree_q.front();
                tree_q.pop();
                for (const auto &neighbor : graph[cur_vertex])
                {
                    if (!visited.count(neighbor))
                        visited[neighbor] = true;
                    else
                        continue;
                    tree_q.emplace(neighbor);
                }
            }
        }
        return dist - 1;
    }

 private:
    void set_edge_from_treenode(TreeNode *u, TreeNode *v, unordered_map<int, vector<int>> &graph)
    {
        if (!u || !v)
            return;
        graph[u->val].emplace_back(v->val);
        graph[v->val].emplace_back(u->val);
    }
    void set_graph_from_tree(TreeNode *root, unordered_map<int, vector<int>> &graph)
    {
        if (!root)
            return;

        set_edge_from_treenode(root, root->left, graph);
        set_edge_from_treenode(root, root->right, graph);

        set_graph_from_tree(root->left, graph);
        set_graph_from_tree(root->right, graph);
    }
};

int main(void)
{

    return 0;
}