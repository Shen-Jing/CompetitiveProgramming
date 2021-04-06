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

const int k_maxn = 1000000 + 5;
array<int, k_maxn> nums;

int main(void)
{
    int kases;
    cin >> kases;
    while (kases--)
    {
        int n;  // number of snowflakes
        cin >> n;

        for (size_t i = 0; i < n; ++i)
            cin >> nums[i];

        set<int> s;
        size_t ans = 0;
        for (size_t left = 0, right = 0; left < n && right < n; )
        {
            while (right < n && !s.count(nums[right])) 
                s.emplace(nums[right++]);
            ans = max(ans, right - left);
            s.erase(nums[left++]);
        }
        cout << ans << "\n";
    }
    return 0;
}