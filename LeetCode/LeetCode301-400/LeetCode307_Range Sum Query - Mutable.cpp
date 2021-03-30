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

class FenwickTree
{
 public:
    FenwickTree() { }
    FenwickTree(vector<int>& nums)
    {
        sz_ = nums.size();
        ft_.assign(sz_ + 1, 0);
        for (size_t i = 0; i < sz_; ++i)
            update(i + 1, nums[i]);
    }

    int lowbit(int val)
    {
        return val & (-val);
    }

    /* All of indices >= 1 */
    void update(int index, int val)
    {
        for ( ; index <= sz_; index += lowbit(index))
            ft_[index] += val;
    }

    int query(int index)
    {
        int sum = 0;
        for ( ; index > 0; index -= lowbit(index))
            sum += ft_[index];
        return sum;
    }
    
    int query(int left, int right)
    {
        return (left == 1) ? query(right) : query(right) - query(left - 1);
    }

  private:
    size_t sz_;
    vector<int> ft_;
};

class NumArray
{
 public:
    FenwickTree ft;
    NumArray(vector<int>& nums)
    {
        nums_ = nums;
        FenwickTree tmp(nums_);
        ft = move(tmp);
    }

    void update(int index, int val)
    {
        ft.update(index + 1, val - nums_[index]);
        nums_[index] = val;
    }
    
    int sumRange(int left, int right)
    {
        return ft.query(left + 1, right + 1);
    }

 private:
    vector<int> nums_;
};

int main(void)
{
    vector<int> nums{1, 3, 5};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0, 2);
    obj->update(1, 2);
    cout << obj->sumRange(0, 2);

    return 0;
}