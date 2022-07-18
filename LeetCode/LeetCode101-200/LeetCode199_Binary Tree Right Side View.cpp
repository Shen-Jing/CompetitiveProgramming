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
    vector<int> rightSideView(TreeNode *root)
    {
        return level_order_traversal(root);
    }

 private:
    void push_children_to_queue(queue<TreeNode *> &q, TreeNode *node)
    {
        if (node->left)
            q.emplace(node->left);
        if (node->right)
            q.emplace(node->right);
    }

    vector<int> level_order_traversal(TreeNode *root)
    {
        vector<int> values;
        if (!root)
            return values;
        queue<TreeNode *> q;
        q.emplace(root);

        while (!q.empty())
        {
            int num_of_nxt_level_nodes = q.size();
            for (int i = 0; i < num_of_nxt_level_nodes; ++i)
            {
                TreeNode *curr_node = q.front();
                q.pop();
                push_children_to_queue(q, curr_node);
                if (i == num_of_nxt_level_nodes - 1)
                    values.emplace_back(curr_node->val);
            }
        }
        return values;
    }
};

int main(void)
{

    return 0;
}