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
#include <sstream>
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
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        return merge_by_sort(intervals);
    }

 private:
    bool is_overlapping(vector<int> &first, vector<int> &second)
    {
        if (first[0] <= second[0] && first[1] >= second[0])
            return true;
        return false;
    }

    vector<vector<int>> merge_by_sort(vector<vector<int>>& intervals)
    {
        remove_reference<decltype(intervals)>::type ans;
        sort(intervals.begin(), intervals.end());

        auto sz = intervals.size();
        auto cur_merged_interval = intervals.front();
        for (int i = 1; i < sz; ++i)
        {
            if (is_overlapping(cur_merged_interval, intervals[i]))
                cur_merged_interval[1] = max(cur_merged_interval[1], intervals[i][1]);
            else
            {
                ans.emplace_back(cur_merged_interval);
                cur_merged_interval = intervals[i];
            }
        }
        ans.emplace_back(cur_merged_interval);
        return ans;
    }
};

int main(void)
{
    Solution sol;

    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    sol.merge(intervals);

    vector<vector<int>> intervals{{1, 4}, {2, 3}};
    sol.merge(intervals);

    return 0;
}