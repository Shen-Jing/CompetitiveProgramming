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
    int removeElement(vector<int> &nums, int val)
    {
        int left, right, sz = nums.size();
        for (left = 0, right = sz - 1; left <= right; )
        {
            while (nums[right] == val)
                --right;
            if (nums[left] == val)
            {
                swap(nums[left], nums[right]);
                --right;
            }
            else 
                ++left;
        }
        return left;
    }
};

int main(void)
{

    return 0;
}