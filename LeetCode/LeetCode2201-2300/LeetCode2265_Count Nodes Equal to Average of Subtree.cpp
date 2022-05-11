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
    int averageOfSubtree(TreeNode* root)
    {
        preorder_sum(root);
        preorder_size(root);
        preorder(root);
        return ans_;
    }

 private:
    unordered_map<TreeNode *, int> subtree_sums;
    unordered_map<TreeNode *, int> subtree_sizes;
    int ans_ = 0;

    void preorder(TreeNode *root)
    {
        if (!root)
            return;
        if (root->val == subtree_sums[root] / subtree_sizes[root])
            ++ans_;
        preorder(root->left);
        preorder(root->right);
    }

    int preorder_size(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return subtree_sizes[root] = 1;
        if (subtree_sizes.count(root))
            return subtree_sizes[root];
        return subtree_sizes[root] = 1 +
                                     preorder_size(root->left) + preorder_size(root->right);
    }

    int preorder_sum(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return subtree_sums[root] = root->val;
        if (subtree_sums.count(root))
            return subtree_sums[root];
        return subtree_sums[root] = root->val +
                                    preorder_sum(root->left) + preorder_sum(root->right);
    }
};

int main(void)
{

    return 0;
}