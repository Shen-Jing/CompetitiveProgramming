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
        return my_lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }

 private:
    template<typename ForwardIt, typename T>
    ForwardIt my_lower_bound(ForwardIt first, ForwardIt last, const T &value)
    {
        ForwardIt mid;
        while (first < last)
        {
            mid = first + (last - first) / 2;
            if (*mid >= value) /* [first, mid) */
                last = mid;
            else /* [mid + 1, last) */
                first = mid + 1;
        }
        return first;
    }
};

int main(void)
{

    return 0;
}