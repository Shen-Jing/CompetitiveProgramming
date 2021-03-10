#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <map>
#include <tuple>
#include <type_traits>
#include <utility>
#include <regex>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *left, TreeNode *right) : val(v), left(left), right(right) {}
}

class Solution
{
 public:

    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        return max(height(root->left), height(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if (!root)
            return true;
        if (abs(height(root->left) - height(root->right)) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }
};

int main(void)
{
    Solution ans;
    
    return 0;
}