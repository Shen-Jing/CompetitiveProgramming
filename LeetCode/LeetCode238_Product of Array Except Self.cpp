class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forward_mul{nums};
        vector<int> backward_mul{nums};
        int sz{nums.size()};
        for (int i = 0; i < sz; ++i)
        {
            forward_mul[i] = accumulate(nums.begin(), nums.begin() + i + 1, nums[0], multiplies<int>());
            backward_mul[sz - i - 1] = accumulate(nums.rbegin(), nums.rbegin() + i + 1, nums[sz - 1], multiplies<int>());
        }
        
        vector<int> ans{forward_mul};
        for (int i = 0; i < sz - 1; ++i)
        {
            ans[i] *= backward_mul[]
        }
        
        return ans;
    }
};
