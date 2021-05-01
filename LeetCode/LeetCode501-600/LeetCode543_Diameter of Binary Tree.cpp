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
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (!root)
            return 0;
        int cur_diameter = get_depth(root->left) + get_depth(root->right);
        int left_diameter = diameterOfBinaryTree(root->left);
        int right_diameter = diameterOfBinaryTree(root->right);
        return max(cur_diameter, max(left_diameter, right_diameter));
    }
  
  private:
    int diameter{0};
    int get_depth(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(get_depth(root->left), get_depth(root->right));
    }
};

int main(void)
{

    return 0;
}