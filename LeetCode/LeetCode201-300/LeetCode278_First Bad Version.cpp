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

bool isBadVersion(int version)
{
    if (version >= 4)
        return true;
    return false;
}

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    int firstBadVersion(int n)
    {
        int first = 1, last = n + 1;
        while (first < last)
        {
            auto mid = first + ((last - first) >> 1);
            if (isBadVersion(mid))
                last = mid;
            else
                first = mid + 1;
        }
        return first;
    }
};

int main(void)
{
    Solution sol;
    sol.firstBadVersion(5);
    sol.firstBadVersion(2147483647);  // 2147483647
    return 0;
}