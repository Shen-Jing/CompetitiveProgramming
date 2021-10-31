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
#include <vector>
#include "utils.hpp"

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> list;
        while (head)
        {
            list.emplace_back(head->val);
            head = head->next;
        }

        auto sz = list.size();
        vector<int> critical_points;
        for (int i = 1; i <= sz - 2; ++i)
        {
            if ((list[i] > list[i - 1] && list[i] > list[i + 1]) ||
                (list[i] < list[i - 1] && list[i] < list[i + 1]))
                critical_points.emplace_back(i);
        }
        if (critical_points.size() < 2)
            return {-1, -1};
        int min_dist = 100000 - 2;
        for (int i = 1; i < critical_points.size(); ++i)
            min_dist = min(min_dist, critical_points[i] - critical_points[i - 1]);
        return {min_dist, critical_points.back() - critical_points.front()};
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums{5,3,1,2,5,1,2};

    return 0;
}