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
    void rotate(vector<int>& nums, int k)
    {
        return rotate_STL(nums, k);
    }

 private:
    void rotate_STL(vector<int> &nums, int k)
    {
        int sz = nums.size();
        int steps = (k > sz) ? k % sz : k;
        std::rotate(nums.rbegin(), nums.rbegin() + steps, nums.rend());
        return;
    }
};