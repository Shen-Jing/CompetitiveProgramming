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
    TreeNode* searchBST(TreeNode* root, int val)
    {

    }

 private:
    TreeNode* search_BST_recursive(TreeNode *root, const int val)
    {
        if (!root || root->val == val)
            return root;
        return (val < root->val) ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};

int main(void)
{

    return 0;
}