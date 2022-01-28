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
    string originalDigits(string s)
    {
        /* Consist of {"e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"} */
        map<char, int> letter_cnt;
        for (const auto &ch : s)
            ++letter_cnt[ch];
        
        array<int, 10> num_cnt;
        num_cnt.fill(0);
        /* First unique: 0 (z), 2 (w), 4 (u), 6 (x), 8 (g) */
        while (letter_cnt['z'])
        {
            ++num_cnt[0];
            --letter_cnt['z'];
            --letter_cnt['e'];
            --letter_cnt['r'];
            --letter_cnt['o'];
            cout << letter_cnt['z'] << endl;
        }

        while (letter_cnt['w'])
        {
            ++num_cnt[2];
            --letter_cnt['t'];
            --letter_cnt['w'];
            --letter_cnt['o'];
        }

        while (letter_cnt['u'])
        {
            ++num_cnt[4];
            --letter_cnt['f'];
            --letter_cnt['o'];
            --letter_cnt['u'];
            --letter_cnt['r'];
        }

        while (letter_cnt['x'])
        {
            ++num_cnt[6];
            --letter_cnt['s'];
            --letter_cnt['i'];
            --letter_cnt['x'];
        }

        while (letter_cnt['g'])
        {
            ++num_cnt[8];
            --letter_cnt['e'];
            --letter_cnt['i'];
            --letter_cnt['g'];
            --letter_cnt['h'];
            --letter_cnt['t'];
        }

        /* Second unique: 1 (o), 3 (r), 5 (f), 7 (s) */
        while (letter_cnt['o'])
        {
            ++num_cnt[1];
            --letter_cnt['o'];
            --letter_cnt['n'];
            --letter_cnt['e'];
        }

        while (letter_cnt['r'])
        {
            ++num_cnt[3];
            --letter_cnt['t'];
            --letter_cnt['h'];
            --letter_cnt['r'];
            --letter_cnt['e'];
            --letter_cnt['e'];
        }

        while (letter_cnt['f'])
        {
            ++num_cnt[5];
            --letter_cnt['f'];
            --letter_cnt['i'];
            --letter_cnt['v'];
            --letter_cnt['e'];
        }

        while (letter_cnt['s'])
        {
            ++num_cnt[7];
            --letter_cnt['s'];
            --letter_cnt['e'];
            --letter_cnt['v'];
            --letter_cnt['e'];
            --letter_cnt['n'];
        }

        /* Final */
        while (letter_cnt['i'])
        {
            ++num_cnt[9];
            --letter_cnt['n'];
            --letter_cnt['i'];
            --letter_cnt['n'];
            --letter_cnt['e'];
        }

        string result;
        for (size_t digit = 0; digit <= 9; ++digit)
            result += string(num_cnt[digit], digit + '0');
        return result;
    }
};

int main(void)
{
    Solution sol;

    sol.originalDigits("zerozero");

    return 0;
}