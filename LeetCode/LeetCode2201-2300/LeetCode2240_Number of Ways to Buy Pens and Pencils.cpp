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
    long long waysToBuyPensPencils(int total, int cost1, int cost2)
    {
        int ans{0};
        int n1 = total / cost1;
        for (int i1{0}; i1 <= n1; ++i1)
        {
            int n2 = (total - i1 * cost1) / cost2;
            ans += (n2 + 1);
        }
        return ans;
    }

 private:
    set<pair<int, int>> ways_;
    long long top_down(int total, const vector<int> &costs, pair<int, int> comb)
    {
        if (total < 0)
        for (const auto &cost : costs)
        {
          ;
        }
        return 1;
    }
};

int main(void)
{

    return 0;
}