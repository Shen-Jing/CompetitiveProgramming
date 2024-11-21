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
    bool canConstruct(string ransomNote, string magazine)
    {
        return by_table(ransomNote, magazine);
    }

 private:
    bool by_table(const string &target, const string &src)
    {
        array<int, 26> letters_cnt;
        letters_cnt.fill(0);
        for (const auto &ch : src)
            ++letters_cnt[ch - 'a'];
        
        for (const auto &ch : target)
        {
            if (!letters_cnt[ch - 'a'])
                return false;
            --letters_cnt[ch - 'a'];
        }
        return true;
    }
};

int main(void)
{

    return 0;
}