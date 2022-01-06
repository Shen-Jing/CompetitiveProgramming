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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        return BFS_marker(root);
    }

 private:
    vector<vector<int>> BFS_marker(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> result;
        vector<int> curr_level;
        queue<TreeNode *> node_q;

        node_q.emplace(root);
        node_q.emplace(nullptr);
        while (!node_q.empty())
        {
            auto node = node_q.front();
            node_q.pop();
            if (!node)
            {
                result.emplace_back(curr_level);
                curr_level.clear();
                if (!node_q.empty())
                    node_q.emplace(nullptr);
            }
            else
            {
                curr_level.emplace_back(node->val);
                if (node->left)
                    node_q.emplace(node->left);
                if (node->right)
                    node_q.emplace(node->right);
            }
        }
        return result;
    }
};

int main(void)
{

    return 0;
}