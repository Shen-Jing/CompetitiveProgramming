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
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
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
    string largestGoodInteger(string num)
    {
        int len = num.length();
        vector<string> digits_3;
        for (int n = 0; n <= 9; ++n)
            digits_3.emplace_back(string(3, '0' + n));
        for (int i = 9; i >= 0; --i)
        {
            if (num.find(digits_3[i]) != num.npos)
                return digits_3[i];
        }
        return "";
    }
};

int main(void)
{
    Solution sol;

    sol.largestGoodInteger("6777133339");
    sol.largestGoodInteger("2300019");
    sol.largestGoodInteger("42352338");

    return 0;
}