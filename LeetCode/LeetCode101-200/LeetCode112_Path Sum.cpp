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
    bool hasPathSum(TreeNode* root, int target_sum)
    {
        return get_path_sum(root, 0, target_sum);
    }

 private:
    /* DLR (inorder) */
    bool get_path_sum(TreeNode *root, int current, int target)
    {
        if (!root)
            return false;
        if (!root->left && !root->right)  // leaf
        {
            if (current + root->val == target)
                return true;
            else
                return false;
        }
        current += root->val;
        return get_path_sum(root->left, current, target) || get_path_sum(root->right, current, target);
    }
};

int main(void)
{

    return 0;
}