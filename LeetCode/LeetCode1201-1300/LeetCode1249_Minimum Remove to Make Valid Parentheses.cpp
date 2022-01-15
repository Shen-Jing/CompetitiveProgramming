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
    string minRemoveToMakeValid(string s)
    {
        return my_try(s);
    }

 private:
    string my_try(const string &str)
    {
        auto len = str.length();
        vector<size_t> removed_indices;
        removed_indices.reserve(len >> 2);
        int balance{0};
        for (size_t i = 0; i < len; ++i)
        {
            if (str[i] == '(')
                ++balance;
            else if (str[i] == ')')
            {
                --balance;
                if (balance < 0)
                    removed_indices.emplace_back(i);
            }
        }
        removed_indices.emplace_back(len);

        string valid_str;
        auto removed_iter = removed_indices.begin();
        for (size_t i = 0; i < len; ++i)
        {
            if (i == *removed_iter)
                ++removed_iter;
            else
                valid_str += str[i];
        }
        return valid_str;
    }
};

int main(void)
{

    return 0;
}