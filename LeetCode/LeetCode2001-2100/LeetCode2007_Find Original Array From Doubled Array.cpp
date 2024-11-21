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
    vector<int> findOriginalArray(vector<int> &changed)
    {
        if (changed.size() & 1)
            return {};
        return by_hash_table(changed);
    }

 private:
    vector<int> by_hash_table(vector<int> &changed)
    {
        unordered_map<int, int> frequencies;
        for (const auto &val : changed)
            ++frequencies[val];

        vector<int> ans;
        sort(changed.begin(), changed.end());
        for (const auto &val : changed)
        {
            if (!frequencies[val])
                continue;
            if (frequencies[val * 2] > 0)
            {
                ans.emplace_back(val);
                --frequencies[val];
                --frequencies[val * 2];
            }
            else
                return {};
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}