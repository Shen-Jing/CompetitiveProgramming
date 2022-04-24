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
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons)
    {
        return brute_force(flowers, persons);
    }

 private:
    vector<int> ans_;
    vector<int> brute_force(const vector<vector<int>> &flowers, const vector<int> &persons)
    {
        int sz = persons.size();
        ans_.assign(sz, 0);
        for (int i = 0; i < sz; ++i)
        {
            for (const auto &flower : flowers)
            {
                const auto &start = flower[0], &end = flower[1];
                if (start <= persons[i] && persons[i] <= end)
                    ++ans_[i];
            }
        }
        return ans_;
    }
};

int main(void)
{

    return 0;
}