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
    int countBinarySubstrings(string s)
    {

    }

 private:
    int brute_force(const string &s)
    {
        int ans{0};
        for (int n = 1; 2 * n <= s.length(); ++n)
        {
            string binary_pattern = string(n, '0') + string(n, '1');
            for (int pos{0}; (pos = s.find(binary_pattern, pos)) != string::npos; ++pos)
                ++ans;
            reverse(binary_pattern.begin(), binary_pattern.end());
            for (int pos{0}; (pos = s.find(binary_pattern, pos)) != string::npos; ++pos)
                ++ans;
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}