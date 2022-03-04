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
    bool isSubsequence(string s, string t)
    {
    }

 private:
    bool is_subseq_recursive(const string &s, const string &t, int s_idx, int t_idx)
    {
        if (s_idx == s.length())
            return true;
        if (t_idx == t.length())
            return false;
        if (s[s_idx] == t[t_idx])
            return is_subseq_recursive(s, t, s_idx + 1, t_idx + 1);
        return is_subseq_recursive(s, t, s_idx, t_idx + 1);
    }
};

int main(void)
{

    return 0;
}