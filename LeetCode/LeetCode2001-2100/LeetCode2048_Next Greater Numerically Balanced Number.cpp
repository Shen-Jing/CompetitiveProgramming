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
    int nextBeautifulNumber(int n)
    {
        vector<int> ans; 
        for (int num = n + 1; ; ++num)
            if (is_balanced(num))
                return num; 
    }

 private:
    bool is_balanced(int num)
    {
        auto str_num = to_string(num);
        array<int, 10> num_occurences;
        num_occurences.fill(0);
        for (const auto &ch : str_num)
            ++num_occurences[ch - '0'];

        for (const auto &ch : str_num)
        {
            int digit = ch - '0';
            if (num_occurences[digit] != digit)
                return false;
        }
        return true;
    }
};

int main(void)
{
    Solution sol;

    cout << sol.nextBeautifulNumber(1) << endl;

    return 0;
}