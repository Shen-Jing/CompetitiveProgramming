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
    bool isPalindrome(int x)
    {
    }

 private:
    bool check_by_string(const int &x)
    {
        if (x < 0)
            return false;
        auto str_x = to_string(x);
        return is_palindrome(str_x);
    }

    bool is_palindrome(const string &str)
    {
        for (int left = 0, right = str.length() - 1; left < right; ++left, --right)
            if (str[left] != str[right])
                return false;
        return true;
    }
};

int main(void)
{

    return 0;
}