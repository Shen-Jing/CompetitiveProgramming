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
    int findTilt(TreeNode *root)
    {
        if (!root)
            return 0;
        int tilt = abs(tree_sum(root->left) - tree_sum(root->right));
        return tilt + findTilt(root->left) + findTilt(root->right);
    }

    /* Pre-order DFS */
    int tree_sum(TreeNode *root)
    {
        if (!root)
            return 0;
        return root->val + tree_sum(root->left) + tree_sum(root->right);
    }
};

int main(void)
{

    return 0;
}