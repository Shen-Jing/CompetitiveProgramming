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
#include <unordered_map>
#include <unordered_set>
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
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
    }

 private:
    bool my_hash_table(vector<int> &nums, int k)
    {
        unordered_map<int, int> num_to_idx;
        int sz = nums.size();
        for (int i = 0; i < sz; ++i)
        {
            if (num_to_idx.count(nums[i]))
            {
                if (i - num_to_idx[nums[i]] <= k)
                    return true;
            }
            num_to_idx[nums[i]] = i;
        }
        return false;
    }
};

int main(void)
{

    return 0;
}