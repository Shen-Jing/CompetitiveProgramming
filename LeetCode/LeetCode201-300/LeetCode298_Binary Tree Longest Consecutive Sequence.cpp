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
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
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
    int longestConsecutive(TreeNode *root)
    {
        inorder_traverse(root, numeric_limits<int>::min(), 1);
        return ans_;
    }

 private:
    int ans_ = 1;
    void inorder_traverse(TreeNode *root, int parent_val, int cur_len)
    {
        if (!root)
        {
            ans_ = max(ans_, cur_len);
            return;
        }
        if (root->val == parent_val + 1)
        {
            ++cur_len;
            ans_ = max(ans_, cur_len);
        }
        else
            cur_len = 1;
        inorder_traverse(root->left, root->val, cur_len);
        inorder_traverse(root->right, root->val, cur_len);
    }
};

int main(void)
{

    return 0;
}