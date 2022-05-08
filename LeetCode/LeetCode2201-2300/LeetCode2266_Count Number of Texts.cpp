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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

/* Boost cpp_int */
class Solution
{
 public:
    int countTexts(string pressedKeys)
    {
        int len = pressedKeys.length(), start_i = 0;
        boost::multiprecision::int128_t ans = 1;
        for (int i = 1; i <= len; ++i)
        {
            if (i == len || pressedKeys[i] != pressedKeys[i - 1])
            {
                string pattern = pressedKeys.substr(start_i, i - start_i);
                int pattern_len = pattern.length();
                // cout << pattern << " ";
                ans *= cnt(pattern, pattern[0] - '0', 0, pattern_len) % (1000000000 + 7);
                ans %= (1000000000 + 7);
                start_i = i;
            }
        }
        cout << ans << "\n";
        // cout << "\n";
        return -1;
    }

 private:
    unordered_map<string, boost::multiprecision::int128_t> msgs;
    // unordered_map<int, string> digits_to_letters
    vector<string> digits_to_letters
    {
        "", "",
        "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    boost::multiprecision::int128_t cnt(const string &pressed_keys, const int digit, int idx, const int &len)
    {
        if (msgs.count(pressed_keys))
            return msgs[pressed_keys];
        if (pressed_keys.length() == 1 || pressed_keys.length() == 0)
            return 1;

        boost::multiprecision::int128_t sum = 0;
        for (int i = 0; i < digits_to_letters[digit].length() && i < pressed_keys.length(); ++i)
        {
            string sub = pressed_keys.substr(i + 1, pressed_keys.length() - (i + 1));
            sum += 1 * cnt(sub, digit, i + 1, len);;
        }
        return msgs[pressed_keys] = sum;
    }
};

int main(void)
{
    Solution sol;

    sol.countTexts("22233");
    sol.countTexts("2266622");
    // Ans: 537551452
    sol.countTexts("444444444444444444444444444444448888888888888888999999999999333333333333333366666666666666662222222222222222666666666666666633333333333333338888888888888888222222222222222244444444444444448888888888888222222222222222288888888888889999999999999999333333333444444664");
    // Ans: 886136986
    sol.countTexts("88888888888888888888888888888999999999999999999999999999994444444444444444444444444444488888888888888888888888888888555555555555555555555555555556666666666666666666666666666666666666666666666666666666666222222222222222222222222222226666666666666666666666666666699999999999999999999999999999888888888888888888888888888885555555555555555555555555555577777777777777777777777777777444444444444444444444444444444444444444444444444444444444433333333333333333333333333333555555555555555555555555555556666666666666666666666666666644444444444444444444444444444999999999999999999999999999996666666666666666666666666666655555555555555555555555555555444444444444444444444444444448888888888888888888888888888855555555555555555555555555555555555555555555555555555555555555555555555555555555555999999999999999555555555555555555555555555554444444444444444444444444444444555");


    return 0;
}