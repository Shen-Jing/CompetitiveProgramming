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
    vector<vector<int>> findLeaves(TreeNode *root)
    {
        return collect_and_mark(root);
    }

 private:
    /* Operate literally */
    vector<vector<int>> collect_and_mark(TreeNode *root)
    {
        vector<vector<int>> result; 
        unordered_set<TreeNode *> done{nullptr};
        while (!done.count(root))
        {
            vector<int> leaves;
            DFS_collect(root, leaves, done);
            result.emplace_back(leaves);
        }
        return result;
    }

    /* DFS preorder */
    void DFS_collect(TreeNode *root, vector<int> &leaves, unordered_set<TreeNode *> &leaves_done)
    {
        if (!root || leaves_done.count(root))
            return;
        if (leaves_done.count(root->left) && leaves_done.count(root->right))
        {
            leaves.emplace_back(root->val);
            leaves_done.emplace(root);
        }
        DFS_collect(root->left, leaves, leaves_done);
        DFS_collect(root->right, leaves, leaves_done);
    }
};

int main(void)
{

    return 0;
}