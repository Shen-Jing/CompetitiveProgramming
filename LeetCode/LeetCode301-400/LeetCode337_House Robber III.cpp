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
    int rob(TreeNode *root)
    {
    }

 private:
    int recursive(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;

        int no_left_child_money{0}, no_right_child_money{0};
        if (root->left)
            no_left_child_money = rob(root->left->left) + rob(root->left->right);
        if (root->right)
            no_right_child_money = rob(root->right->left) + rob(root->right->right);
        /* Not rob the current or
           rob the current (no left & right child) */
        return max(rob(root->left) + rob(root->right),
                   root->val + no_left_child_money + no_right_child_money); 
    }
};

int main(void)
{

    return 0;
}