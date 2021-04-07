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

vector<int> counting_sort(vector<int> nums)
{
    const auto [min, max] = minmax_element(nums.begin(), nums.end());
    const auto range = *max - *min + 1;

    vector<int> prefix_sum(range);

    /* Frequency */
    for (const auto &num : nums)
        ++prefix_sum[num - *min];
    
    /* Prefix Sum */
    for (size_t i = 1; i < range; ++i)
        prefix_sum[i] += prefix_sum[i - 1];
    
    /* Placement */
    vector<int> output(nums.size());
    for (auto it = nums.rbegin(); it < nums.rend(); ++it)
    {
        auto &target = prefix_sum[*it - *min];
        output[target - 1] = *it;
        --target;
    }
    return output;
}

int main(void)
{
    int n;
    while (cin >> n)
    {
        if (!n)
            break;
        vector<int> ages;  // [1, 99]
        ages.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            int age;
            cin >> age;
            ages.emplace_back(age);
        }

        const auto output = counting_sort(ages);
        const auto sz = output.size();
        cout << output[0];
        for (size_t i = 1; i < sz; ++i)
            cout << " " << output[i];
        cout << "\n";
    }
    return 0;
}