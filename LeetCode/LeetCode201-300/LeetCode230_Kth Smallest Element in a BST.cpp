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
    int kthSmallest(TreeNode *root, int k) 
    {
        int ans{-1}, idx{0};
        DFS_inorder(root, ans, idx, k);
        return ans;
    }

 private:
    // void *helper(TreeNode *root, TreeNode *&ans, int idx, int k)
    void DFS_inorder(TreeNode *root, int &ans, int &idx, int k)
    {
        if (ans != -1)
            return;
        if (!root)
            return;
        DFS_inorder(root->left, ans, idx, k);
        ++idx;
        if (idx == k)
        {
            ans = root->val;
            return;
        }
        DFS_inorder(root->right, ans, idx, k);
    }
};

int main(void)
{

    return 0;
}