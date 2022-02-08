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
    bool containsDuplicate(vector<int> &nums)
    {
        return detect_by_hash_table(nums);
    }

 private:
    bool detect_by_hash_table(vector<int> &nums)
    {
        unordered_map<int, int> nums_counter;
        for (const auto &num : nums)
        {
            ++nums_counter[num];
            if (nums_counter[num] > 1)
                return true;
        }
        return false;
    }
};

int main(void)
{

    return 0;
}