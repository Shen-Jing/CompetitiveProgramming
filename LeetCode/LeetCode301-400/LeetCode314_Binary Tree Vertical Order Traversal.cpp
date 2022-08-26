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
    vector<vector<int>> verticalOrder(TreeNode* root)
    {
        if (!root)
            return vector<vector<int>>{};
        BFS_queue.emplace(root);
        nodes_cols[0].emplace_back(root->val);
        node2col[root] = 0;
        while (!BFS_queue.empty())
        {
            int cur_level_nodes = BFS_queue.size();
            for (int i = 0; i < cur_level_nodes; ++i)
            {
                auto cur_node = BFS_queue.front();
                BFS_queue.pop();
                if (cur_node->left)
                    process_new_node(cur_node, cur_node->left, true);
                if (cur_node->right)
                    process_new_node(cur_node, cur_node->right, false);
            }
        }

        vector<vector<int>> ans;
        for (int c = min_col; c <= max_col; ++c)
        {
            ans.emplace_back(nodes_cols[c]);
        }
        return ans;
    }

 private:
    queue<TreeNode *> BFS_queue;
    unordered_map<int, vector<int>> nodes_cols;  // 2D coordinates of nodes
    unordered_map<TreeNode *, int> node2col;
    int min_col = 0, max_col = 0;
    void process_new_node(TreeNode *node, TreeNode *child_node, bool is_left = true)
    {
        int col = node2col[node];
        if (is_left)
        {
            --col;
        }
        else
        {
            ++col;
        }
        BFS_queue.emplace(child_node);
        node2col[child_node] = col;
        nodes_cols[col].emplace_back(child_node->val);
        min_col = min(min_col, col);
        max_col = max(max_col, col);
    }
};

int main(void)
{

    return 0;
}