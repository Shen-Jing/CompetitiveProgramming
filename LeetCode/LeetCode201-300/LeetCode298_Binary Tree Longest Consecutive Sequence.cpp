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
    int longestConsecutive(TreeNode *root)
    {
        return helper(root);
    }

 private:
    int ans_ = 1;
    int helper(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int left_len{0}, right_len{0};
        if (root->left && root->left->val == root->val + 1)
            left_len = 1 + helper(root->left);
        if (root->right && root->right->val == root->val + 1)
            right_len = 1 + helper(root->right);
        return max(left_len, right_len);
    }

};

int main(void)
{

    return 0;
}