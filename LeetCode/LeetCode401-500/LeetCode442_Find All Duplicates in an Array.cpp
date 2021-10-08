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
    vector<int> findDuplicates(vector<int>& nums) 
    {
        frequencies.fill(0);
        simple_count(nums);
        return ans;
    }

 private:
    static const int max_num = 100000 + 1;
    array<int, max_num> frequencies;
    vector<int> ans;
    void simple_count(const vector<int> &nums)
    {
        for (const auto &num : nums)
            ++frequencies[num];
        for (int i = 0; i < max_num; ++i)
            if (frequencies[i] == 2)
                ans.emplace_back(i);
    }
};

int main(void)
{

    return 0;
}