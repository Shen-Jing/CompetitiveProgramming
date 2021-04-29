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
    bool isValidBST(TreeNode* root)
    {
        return check_BST_inorder(root);
    }
 
 private:
    int upper_limit, lower_limit;
    TreeNode *prev_;

    bool check_BST_inorder(TreeNode *root)
    {
        if (!root)
            return true;
        if (!check_BST_inorder(root->left))
            return false;
        if (prev_ != nullptr && root->val <= prev_->val)
            return false;
        prev_ = root;
        return check_BST_inorder(root->right);
    }
};

int main(void)
{

    return 0;
}