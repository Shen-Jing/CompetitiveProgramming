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

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        top_K_frequent_heap(nums, k);
        return ans_;
    }

 private:
    vector<int> ans_;

    void top_K_frequent_heap(vector<int>& nums, int k)
    {
        unordered_map<int, int> freqencies;
        for (const int &num : nums)
            ++freqencies[num];
        priority_queue<pair<int, int>> sorted_freq;
        for (const auto &[num, freq] : freqencies)
            sorted_freq.push(make_pair(freq, num));

        for (int i = 1; i <= k; ++i)
        {
            auto &frequency = sorted_freq.top();
            ans_.emplace_back(frequency.second);
            sorted_freq.pop();
        }
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{1,1,1,2,2,3};
    sol.topKFrequent(nums, 2);
    return 0;
}