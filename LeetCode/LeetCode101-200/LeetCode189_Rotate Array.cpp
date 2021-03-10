class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz{nums.size()};
        int steps = (k > sz) ? k - sz : k;
        std::rotate(nums.rbegin(), nums.rbegin() + steps, nums.rend());
        return;
    }
};