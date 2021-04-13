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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> output;
        output.reserve(100);
        sub_inorder(root, output);
        return output;
    }
 
 private:
    void sub_inorder(TreeNode *root, vector<int> &output)
    {
        if (!root)
            return;
        sub_inorder(root->left, output);
        output.emplace_back(root->val);
        sub_inorder(root->right, output);
    }
};

int main(void)
{

    return 0;
}