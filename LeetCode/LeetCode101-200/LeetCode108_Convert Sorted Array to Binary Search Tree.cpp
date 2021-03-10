/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static auto io = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int sz = static_cast<int>(nums.size());
        if (sz == 0)
            return nullptr;
        TreeNode *nd = new TreeNode(nums[sz / 2]);
        std::vector<int> left_tmp(nums.begin(), nums.begin() + sz / 2);
        std::vector<int> right_tmp(nums.begin() + sz / 2 + 1, nums.end());
        nd->left = sortedArrayToBST(left_tmp);
        nd->right = sortedArrayToBST(right_tmp);
        return nd;
    }
};