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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum{0};
        range_sum_BST(root, low, high, sum);
        return sum;
    }

    /* DFS preorder */
    void range_sum_BST(TreeNode *root, const int &low, const int &high, int &sum)
    {
        if (!root)
            return;
        if (low <= root->val && root->val <= high)
            sum += root->val;
        range_sum_BST(root->left, low, high, sum);
        range_sum_BST(root->right, low, high, sum);
    }
};

int main(void)
{

    return 0;
}