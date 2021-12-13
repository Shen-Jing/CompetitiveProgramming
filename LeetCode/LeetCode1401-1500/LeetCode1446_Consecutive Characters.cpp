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

constexpr int alphabet_size{26};

class Solution
{
 public:
    int maxPower(string s)
    {
        max_lengths.fill(0);
        int cur_len{1};
        for (size_t i = 1; i < s.size(); ++i)
        {
            if (s[i] != s[i - 1])
            {
                int ch_ascii = s[i - 1] - 'a';
                max_lengths[ch_ascii] = max(max_lengths[ch_ascii], cur_len);
                cur_len = 1;
            }
            else
                ++cur_len;
        }
        int ch_ascii = s[s.size() - 1] - 'a';
        max_lengths[ch_ascii] = max(max_lengths[ch_ascii], cur_len);
        return *max_element(begin(max_lengths), end(max_lengths));
    }

 private:
    array<int, alphabet_size> max_lengths;
};

int main(void)
{

    return 0;
}