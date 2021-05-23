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
    int countSubstrings(string s)
    {
        return count_substrings_by_DP(s);
    }
 
 private:
    int count_substrings_by_DP(const string &input)
    {
        const int len = input.length();
        /* [start][end]: palindromic lenght of substr(start, end - start + 1) */
        vector<vector<int>> palindrome_len(len, vector<int>(len, 0));

        /* [Start, End] */
        for (int s = len - 1; s >= 0; --s)
            for (int e = s; e < len; ++e)
            {
                if (s == e)
                    palindrome_len[s][e] = 1;
                else
                    palindrome_len[s][e] = (input[s] == input[e] && (e - s == 1 || palindrome_len[s + 1][e - 1] > 0))
                                         ? palindrome_len[s + 1][e - 1] + 2
                                         : 0;
            }
        
        int cnt = 0;
        for (auto &outer : palindrome_len)
            for (auto &inner : outer)
                cnt += (inner != 0);
        return cnt;
    }
};

int main(void)
{
    Solution sol;
    
    sol.countSubstrings("aaa");
    sol.countSubstrings("fdsklf");

    return 0;
}