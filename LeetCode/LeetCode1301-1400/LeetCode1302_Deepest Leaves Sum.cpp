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
    int deepestLeavesSum(TreeNode* root)
    {
        return level_order(root);
    }

 private:
    int level_order(TreeNode *root)
    {
        int leave_sum{0};
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty())
        {
            int curr_level_size = q.size();
            leave_sum = 0;
            for (int i = 0; i < curr_level_size; ++i)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left)
                    q.emplace(curr->left);
                if (curr->right)
                    q.emplace(curr->right);
                /* Collect the sum of the current level */
                if (!curr->left && !curr->right)
                    leave_sum += curr->val;
            }
        }
        return leave_sum;
    }
};

int main(void)
{

    return 0;
}