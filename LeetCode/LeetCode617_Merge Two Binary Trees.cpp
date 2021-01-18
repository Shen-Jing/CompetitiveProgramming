#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <vector>

static auto io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Equal to BFS */
void level_traversal(TreeNode * node, std::vector<int> & vec_tree)
{
    std::queue<TreeNode *> q; 
    for (q.emplace(node); !q.empty(); )
    {
        TreeNode * node = q.front();
        q.pop();
        vec_tree.emplace_back(node->val);

        if (node->left)
            q.push(node->left);
        else
            vec_tree.emplace_back(0);
        if (node->right)
            q.push(node->right);
        else
            vec_tree.emplace_back(0);
    }
}

//TreeNode * get_node(std::vector<int> t, int idx)
//{
//    if (idx > t.size())
//        return TreeNode()
//}

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        std::vector<int> vec_t1;
        std::vector<int> vec_t2;
        level_traversal(t1, vec_t1);
        level_traversal(t2, vec_t2);
        auto t1_size = vec_t1.size(), t2_size = vec_t2.size();
        std::vector<int> vec_ans(std::max(t1_size, t2_size), 0);
        /* Merge two trees */
        for (int i = 0; i < vec_ans.size(); ++i)
        {
            int t1_ele = (i > t1_size) ? 0 : vec_t1[i];
            int t2_ele = (i > t2_size) ? 0 : vec_t2[i];
            vec_ans[i] = t1_ele + t2_ele;
        }

        std::copy(vec_ans.begin(), vec_ans.end(), std::ostream_iterator<int>(std::cout, " "));

        /* Build tree from vector */
     //   TreeNode * t_ans(vec_ans[0]);
     //   for (int i = 1; i < vec_ans.size(); ++i)
     //   {
     //       TreeNode * node(vec_ans[1]);
     //       t_ans.left = get_node(vec_ans, i);

     //   }
    }
};

int main(void)
{
    Solution sol;

    return 0;
}
