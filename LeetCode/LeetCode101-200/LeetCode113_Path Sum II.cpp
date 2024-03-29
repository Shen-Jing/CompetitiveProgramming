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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path_list;
        DFS_backtrack(root, targetSum, path_list);
        return ans_lists_;
    }

 private:
    vector<vector<int>> ans_lists_;
    /* Preorder DFS */
    void DFS_backtrack(TreeNode *root, int target_sum, vector<int> &path_list)
    {
        if (!root)
            return;
        
        path_list.emplace_back(root->val);
        if (!root->left && !root->right && root->val == target_sum)
        {
            ans_lists_.emplace_back(path_list);
        }
        else
        {
            target_sum -= root->val;
            DFS_backtrack(root->left, target_sum, path_list);
            DFS_backtrack(root->right, target_sum, path_list);
        }
        path_list.pop_back();
    }
};

int main(void)
{

    return 0;
}