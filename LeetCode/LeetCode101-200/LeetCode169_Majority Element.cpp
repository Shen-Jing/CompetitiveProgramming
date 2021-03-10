static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> cnts;
        for (auto i : nums)
        {
            if (!cnts.count(i))
                cnts[i] = 0;
            ++cnts[i];
        }
        int threshold = nums.size() / 2;
        for (auto &[num, cnt] : cnts)
            if (cnt > threshold)
                return num;
        return nums[0];
    }
};