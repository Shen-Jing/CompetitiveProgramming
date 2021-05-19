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
    bool isPalindrome(string s)
    {
        string valid_str;
        for (const auto &ch : s)
            if (
                ('0' <= ch && ch <= '9') ||
                ('A' <= ch && ch <= 'Z') ||
                ('a' <= ch && ch <= 'z')
               )
                valid_str += tolower(ch);
        return is_palindrome(valid_str);
    }

    bool is_palindrome(const string &s)
    {
        if (s.empty())
            return true;
        return s.front() == s.back() && is_palindrome(s.substr(1, s.length() - 2));
    }
};

int main(void)
{

    return 0;
}