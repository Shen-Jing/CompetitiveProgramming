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
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        return by_sort(properties);
    }

 private:
    int by_sort(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end());
        int sz = properties.size(), ans = 0;
        for (int i = 0; i < sz - 1; ++i)
            for (int j = i + 1; j < sz; ++j)
            {
                if (properties[i][0] < properties[j][0] && properties[i][1] < properties[j][1])
                {
                    ++ans;
                    break;
                }
            }
        return ans;
    }
};

int main(void)
{

    return 0;
}