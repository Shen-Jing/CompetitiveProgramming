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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        for (int i = 0; i < gas.size(); ++i)
            if (can_complete(gas, cost, i))
                return i;
        return -1;
    }

 private:
    bool can_complete(const vector<int> &gas, vector<int> &cost, int idx)
    {
        int tank = gas[idx] - cost[idx];
        for (int i = (idx + 1) % gas.size(); i != idx; i = (i + 1) % gas.size())
        {
            if (tank < 0)
                return false;
            tank += gas[i] - cost[i];
        }
        if (tank < 0)
            return false;
        return true;
    }
};

int main(void)
{

    return 0;
}