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
    /**
     * The performance: (the sum of speeds) ✗ (the min efficiency)
     * @param speed 
     * @param efficiency Bottleneck
     */
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int num_of_members)
    {
        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; ++i)
        {
            engineers.emplace_back(efficiency[i], speed[i]);
        }
        sort(engineers.rbegin(), engineers.rend());  // Desending
        uint64_t sum_speed = 0, max_performance = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; ++i)
        {
            if (pq.size() == num_of_members)
            {
                auto min_speed = pq.top();
                pq.pop();
                sum_speed -= min_speed;
            }

            const int &cur_speed = engineers[i].second;
            pq.emplace(cur_speed);
            sum_speed += cur_speed;
            max_performance = max(max_performance, sum_speed * engineers[i].first);  // Use current efficiency as min
        }
        return max_performance % kModulo;
    }

 private:
    const int kModulo = 1000000000 + 7;
};

int main(void)
{

    return 0;
}