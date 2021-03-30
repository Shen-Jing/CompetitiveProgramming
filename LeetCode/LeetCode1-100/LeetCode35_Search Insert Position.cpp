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
    int searchInsert(vector<int>& nums, int target) 
    {
        size_t sz = nums.size();
        size_t first{0}, last = sz - 1;
        size_t mid = (first + last) / 2;
        for ( ; mid < sz; mid = (first + last) / 2)
        {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
            {
                first = mid;
            }
            else
            {
                last = mid;
            }
        }
        return -1;
    }
};

int main(void)
{

    return 0;
}