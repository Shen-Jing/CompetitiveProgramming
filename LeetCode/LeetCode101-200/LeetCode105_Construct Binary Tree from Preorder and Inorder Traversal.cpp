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
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return array_to_tree(preorder, 0, preorder.size() - 1,
                   inorder, 0, inorder.size() - 1);
    }

 private:
    /* [start, end] */
    TreeNode* array_to_tree(const vector<int> &preorder, const int pre_start, const int pre_end, 
                  const vector<int> &inorder, const int in_start, const int in_end)
    {
        if (pre_start > pre_end)
            return nullptr;
        int root_val = preorder[pre_start],
            in_root = find(inorder.begin(), inorder.end(), root_val) - inorder.begin();
        int left_subtree_size = in_root - in_start,
            right_subtree_size = in_end - in_root;
        
        TreeNode *root = new TreeNode(root_val);
        root->left = array_to_tree(preorder, pre_start + 1, pre_start + left_subtree_size,
                         inorder, in_start, in_root - 1);
        root->right = array_to_tree(preorder, pre_start + left_subtree_size + 1, pre_end,
                          inorder, in_root + 1, in_end);
        return root;
    }
};

int main(void)
{
    Solution sol;

    vector<int> preorder{3,9,20,15,7}, inorder{9,3,15,20,7};
    sol.buildTree(preorder, inorder);

    return 0;
}