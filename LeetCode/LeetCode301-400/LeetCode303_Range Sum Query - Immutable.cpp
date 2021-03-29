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

class NumArray
{
 public:
    NumArray(vector<int>& nums)
    {
        auto sz = nums.size();
        sum_ = nums;
        for (size_t i = 1; i < sz; ++i)
            sum_[i] += sum_[i - 1];
    }
    
    int sumRange(int left, int right)
    {
        return (left) ? (sum_[right] - sum_[left - 1]) : sum_[right];
    }

  private:
    vector<int> sum_;
};

int main(void)
{

    return 0;
}