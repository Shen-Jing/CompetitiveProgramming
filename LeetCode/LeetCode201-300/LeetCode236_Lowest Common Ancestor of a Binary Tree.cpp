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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    TreeNode* oldMethod(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root)
            return nullptr;

        int test{0};
        if (root == p || root == q)
            ++test;
        if (is_exist_byDFS(root->left, p, q))
            ++test;
        if (is_exist_byDFS(root->right, p, q))
            ++test;
        
        if (test == 2)
            return root;
        
        TreeNode *left_res = lowestCommonAncestor(root->left, p, q),
                 *right_res = lowestCommonAncestor(root->right, p, q);
        if (!left_res)
            return right_res;
        return left_res;
    }

 private:
    bool is_exist_byDFS(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return false;
        if (root == p || root == q)
            return true;
        return is_exist_byDFS(root->left, p, q) || is_exist_byDFS(root->right, p, q);
    }
};

int main(void)
{

    return 0;
}