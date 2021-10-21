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
    string reverseWords(string s)
    {
        vector<string> words;
        string word;
        for (const auto &ch : s)
        {
            if (ch == ' ' && !word.empty())
            {
                words.emplace_back(word);
                word.clear();
            }
            else if (ch != ' ')
                word += ch;
        }

        string result = (!word.empty()) ? word + " " : "";
        for (auto it = words.crbegin(); it != words.crend(); ++it)
            result += *it + " "; 
        result.pop_back();
        return result;
    }
};

int main(void)
{
    Solution sol;

    string s{"the sky is blue"};
    // cout << sol.reverseWords(s) << endl;

    cout << sol.reverseWords("  hello world  ") << endl;

    return 0;
}