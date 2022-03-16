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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> stk;
        int pop_idx{0};
        for (const auto &val : pushed)
        {
            stk.emplace(val);
            while (!stk.empty() && stk.top() == popped[pop_idx])
            {
                stk.pop();
                ++pop_idx;
            }
        }
        return !stk.empty() ? false : true;
    }
};

int main(void)
{

    return 0;
}