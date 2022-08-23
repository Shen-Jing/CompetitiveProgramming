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
    int firstUniqChar(string s)
    {
    }

 private:
    /* Written on 2019 */
    int hashtable_and_find_forward(string s)
    {
        std::map<char, int> wrd_rcd;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!wrd_rcd.count(s[i]))
            {
                int pos = s.find(s[i], i + 1);
                if (pos == std::string::npos)
                    return i;
                wrd_rcd[s[i]] = pos;
            }
        }
        return -1;
    }

    int two_pass_by_hash_table(string s)
    {
        unordered_map<int, int> char_cnts;
        for (const auto &ch : s)
            ++char_cnts[ch];
        
        for (int i = 0; i < s.length(); ++i)
        {
            if (char_cnts[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main(void)
{

    return 0;
}