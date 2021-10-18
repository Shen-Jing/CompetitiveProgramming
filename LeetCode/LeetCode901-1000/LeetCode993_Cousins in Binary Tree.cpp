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
    bool isCousins(TreeNode* root, int x, int y)
    {
        array<TreeNode *, 2> parents;
        array<int, 2> depths;
        parents[0] = root;
        parents[1] = root;

        depths[0] = get_depth(root, parents[0], 0, x);
        depths[1] = get_depth(root, parents[1], 0, y);
        return parents[0] != parents[1] && depths[0] == depths[1];
    }

 private:
    int get_depth(TreeNode *root, TreeNode *parent, int depth, int target)
    {
        if (!root)
            return 0;
        if (root->val == target)
            return depth;
        return get_depth(root->left, root, depth + 1, target) + get_depth(root->right, root, depth + 1, target);
    }
};

int main(void)
{

    return 0;
}