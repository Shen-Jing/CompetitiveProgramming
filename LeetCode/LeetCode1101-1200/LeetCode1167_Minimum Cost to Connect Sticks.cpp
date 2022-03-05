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
    int connectSticks(vector<int>& sticks)
    {
        return greedy(sticks);
    }

 private:
    template<typename Set>
    int pop_min_from_set(Set &s)
    {
        const auto min_value = *s.begin();
        s.erase(s.begin());
        return min_value;
    }

    int greedy(vector<int> &sticks)
    {
        multiset<int> sticks_multiset;
        for (const auto &stick : sticks)
            sticks_multiset.emplace(stick);
        
        int cost{0};
        while (sticks_multiset.size() != 1)
        {
            const auto min1 = pop_min_from_set(sticks_multiset),
                       min2 = pop_min_from_set(sticks_multiset);
            const int curr_cost = min1 + min2;
            sticks_multiset.emplace(curr_cost);
            cost += curr_cost;
        }
        return cost;
    }
};

int main(void)
{
    Solution sol;

    vector<int> sticks;
    
    sticks = {2,4,3,1,8,5};
    sol.connectSticks(sticks);

    return 0;
}