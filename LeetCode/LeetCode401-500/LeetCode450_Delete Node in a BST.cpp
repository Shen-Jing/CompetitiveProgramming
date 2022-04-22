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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        /* Search given key */
        if (root->val == key)
        {
            TreeNode *switched_node = get_max_node(root->left);
            if (!switched_node)
            {
                switched_node = get_min_node(root->right);
            }
            /* How to know to deleted node is left or right child of parent? */
            parent->left = switched_node;
        }
        return root;
    }
 
 private:
    TreeNode *get_max_node(TreeNode *root)
    {
        if (!root)
            return nullptr;
        if (!root->left && !root->right)
            return root;
        if (!root->right)
            return get_max_node(root->left);
        return get_max_node(root->right);
    }
};

int main(void)
{

    return 0;
}