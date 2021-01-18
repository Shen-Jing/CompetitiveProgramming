class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int sz{nums.size()};
        my_permute(ans, nums, 0, sz);
        return ans;
    }
    void my_permute(vector<vector<int>> &ans, vector<int> &nums, int idx, int &sz)
    {
        if (idx == sz - 1)
        {
            ans.emplace_back(nums);
            return;
        }
        for (int i = idx; i < sz; ++i)
        {
            swap(nums[idx], nums[i]);
            my_permute(ans, nums, idx + 1, sz);
            swap(nums[idx], nums[i]);
        }
        return;
    }
};