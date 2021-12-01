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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        auto sz = temperatures.size();
        vector<int> ans(sz, 0);
        for (int i = sz - 2; i >= 0; --i)
        {
            int next_i{i + 1};
            while (next_i < sz)
            {
                if (temperatures[next_i] > temperatures[i])
                {
                    ans[i] = next_i - i;
                    break;
                }
                else
                {
                    next_i = next_i + ans[next_i];
                    if (next_i == sz - 1)
                    {
                        ans[i] = 0;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}