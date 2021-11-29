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
    int sumNumbers(TreeNode *root)
    {
        sum_root2leaf(root, "0");
        return sum;
    }
 private:    
    int sum{0};
    /* By DFS */
    void sum_root2leaf(TreeNode *root, string cur_num)
    {
        if (!root)
            return;
        cur_num += to_string(root->val);
        /* Leaf */
        if (!root->left && !root->right)
        {
            sum += stoi(cur_num, nullptr, 10);
            return;
        }
        sum_root2leaf(root->left, cur_num);
        sum_root2leaf(root->right, cur_num);
    }
};

int main(void)
{

    return 0;
}