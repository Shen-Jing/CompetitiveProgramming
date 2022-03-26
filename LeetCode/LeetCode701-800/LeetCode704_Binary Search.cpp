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
    int search(vector<int>& nums, int target)
    {
        int first{0}, last = nums.size();
        while (first < last)
        {
            int mid = first + ((last - first) >> 1);
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                first = mid + 1;
            else
                last = mid;
        }
        return -1;
    }
};

int main(void)
{

    return 0;
}