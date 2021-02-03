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
#include <stack>
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
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        ans.reserve(strs.size());
        unordered_map<string, int> sorted_to_groupid;
        int num_of_anagrams = 0;
        for (auto &s : strs)
        {
            auto sorted_str = s;
            sort(sorted_str.begin(), sorted_str.end());
            if (sorted_to_groupid.count(sorted_str))
                ans[sorted_to_groupid[sorted_str]].emplace_back(s);
            else
            {
                ans.emplace_back(vector<string>{s});
                sorted_to_groupid[sorted_str] = num_of_anagrams++;
            }
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}