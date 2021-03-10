static auto io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!nums[i])
                ++cnt;
            else
                nums[i - cnt] = nums[i];
        }
        //std::transform(nums.begin() + cnt + 1, nums.end(), nums.begin() + cnt + 1, 
                       //[](int ele) { return 0; });
        return;
    }
};