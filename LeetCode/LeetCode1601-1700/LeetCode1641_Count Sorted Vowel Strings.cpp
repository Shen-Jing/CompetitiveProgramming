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
    int countVowelStrings(int n)
    {
        my_backtrack(0, 0, n);
        return ans_;
    }

 private:
    string str_vowels_{"aeiou"};
    const int k_num_of_vowels_{5};
    int ans_{0};
    void my_backtrack(int vow_idx, int cur_len, const int &n)
    {
        if (cur_len == n)
        {
            ++ans_;
            return;
        }
        ++cur_len;
        for (int i = vow_idx; i < k_num_of_vowels_; ++i)
        {
            my_backtrack(i, cur_len, n);
        }
    }
};

int main(void)
{

    return 0;
}