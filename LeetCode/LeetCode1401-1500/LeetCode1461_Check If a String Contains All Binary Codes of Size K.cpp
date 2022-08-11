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
    bool hasAllCodes(string s, int k)
    {
        unordered_set<string> binary_codes;
        string code;
        generate_bicodes(binary_codes, code, 0, k);
        for (int start = 0; start + k - 1 < s.length(); ++start)
        {
            string substring = s.substr(start, k);
            if (binary_codes.find(substring) != binary_codes.end())
            {
                binary_codes.erase(substring);
            }
        }
        return binary_codes.empty();
    }

 private:
    void generate_bicodes(unordered_set<string> &codes, string &code, int cur, const int &len)
    {
        if (cur == len)
        {
            codes.emplace(code);
            return;
        }
        for (int i = cur; i < len; ++i)
        {
            code.push_back('0');
            generate_bicodes(codes, code, cur + 1, len);
            code.pop_back();

            code.push_back('1');
            generate_bicodes(codes, code, cur + 1, len);
            code.pop_back();
        }
    }
};

int main(void)
{
    Solution sol;
    string s;

    s = "00110110";
    cout << sol.hasAllCodes(s, 3);

    return 0;
}