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
    bool isCousins(TreeNode* root, int x, int y)
    {
        parents[0] = nullptr;
        parents[1] = nullptr;
        targets[0] = x;
        targets[1] = y;
        preorder(root, 0);
        return parents[0] != parents[1] && depths[0] == depths[1];
    }

 private:
    array<TreeNode *, 2> parents;
    array<int, 2> depths;
    array<int, 2> targets;
    void preorder(TreeNode *root, int depth)
    {
        if (!root)
            return;
        if (root->left)
        {
            auto result = find(targets.begin(), targets.end(), root->left->val);
            if (result != targets.end())
            {
                size_t target_idx = result - targets.begin();
                parents[target_idx] = root;
                depths[target_idx] = depth + 1;
            }
        }
        if (root->right)
        {
            auto result = find(targets.begin(), targets.end(), root->right->val);
            if (result != targets.end())
            {
                size_t target_idx = result - targets.begin();
                parents[target_idx] = root;
                depths[target_idx] = depth + 1;
            }
        }
        preorder(root->left, depth + 1);
        preorder(root->right, depth + 1);
    }
};

int main(void)
{
    Solution sol;
    return 0;
}