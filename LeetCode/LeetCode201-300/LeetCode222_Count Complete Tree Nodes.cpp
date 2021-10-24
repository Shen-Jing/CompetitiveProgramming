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
    int countNodes(TreeNode *root)
    {
        return BFS(root);
    }

 private:
    int BFS(TreeNode *root)
    {
        int nodes = 0;
        queue<TreeNode *> nodes_q;
        nodes_q.emplace(root);
        while (!nodes_q.empty())
        {
            auto cur_node = nodes_q.front();
            nodes_q.pop();
            if (cur_node)
            {
                ++nodes;
                nodes_q.emplace(cur_node->left);
                nodes_q.emplace(cur_node->right);
            }
        }
        return nodes;
    }
};

int main(void)
{

    return 0;
}