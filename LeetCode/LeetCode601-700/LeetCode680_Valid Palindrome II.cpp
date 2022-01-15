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
    bool validPalindrome(string s)
    {
        return brute_force(s);
    }

 private:
    bool is_valid_palindrome(const string &s, size_t removed_idx)
    {
        for (size_t left{0}, right{s.size() - 1}; left < right; )
        {
            if (left == removed_idx || !isalnum(s[left]))
                ++left;
            else if (right == removed_idx || !isalnum(s[right]))
                --right;
            else if (tolower(s[left]) == tolower(s[right]))
            {
                ++left;
                --right;
            }
            else
                return false;
        }
        return true;
    }

    bool brute_force(const string &s)
    {
        for (size_t i = 0; i < s.size(); ++i)
            if (is_valid_palindrome(s, i))
                return true;
        return false;
    }
};

int main(void)
{

    return 0;
}