static auto io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        // std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
        int i = 1;
        int cnt = 1;
        for (; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
                ++cnt;
            else 
            {
                if (cnt == 1)
                    return nums[i - 1];
                cnt = 1;
            }
        }
        return nums[i - 1];
    }
};