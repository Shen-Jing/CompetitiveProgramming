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
    int sumOfLeftLeaves(TreeNode *root)
    {
        return sum_of_left_leaves(root);
    }

    /* Child label: N(one), L(eft), R(ig) */
    int sum_of_left_leaves(TreeNode *root, char child_label = 'N')
    {
        if (!root)
            return 0;
        if (!root->left && !root->right && child_label == 'L')  // Leaf
            return root->val;
        return sum_of_left_leaves(root->left, 'L') + sum_of_left_leaves(root->right, 'R');
    }
};

int main(void)
{

    return 0;
}