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
    int countDays(int days, vector<vector<int>>& meetings)
    {
        return lineSweep(days, meetings);
    }

 private:
    int lineSweep(int days, vector<vector<int>> &meetings)
    {
        struct Interval
        {
            int time;
            enum class Status
            {
                Start = 0,
                End = 1,
            } status;
            bool operator<(const Interval &other)
            {
                if (this->time != other.time)
                    return this->time < other.time;
                return this->status < other.status;
            }
        };
        
        vector<Interval> intervals;
        for (const auto &meeting : meetings)
        {
            intervals.emplace_back(meeting[0], Interval::Status::Start);
            intervals.emplace_back(meeting[1], Interval::Status::End);
        }
        sort(intervals.begin(), intervals.end());

        int free_time = 0,
            prev_free = 1;
        int occupied = 0;
        for (const auto &interval : intervals)
        {
            if (interval.status == Interval::Status::Start)
            {
                if (!occupied)
                {
                    free_time += interval.time - prev_free;
                }
                ++occupied;
            }
            else
            {
                --occupied;
                if (!occupied)
                {
                    prev_free = interval.time + 1;
                }
            }
        }
        free_time += days - prev_free + 1;
        return free_time;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> meetings;

    // meetings.assign({{5,7}, {1,3}, {9,10}});
    // sol.countDays(10, meetings);

    /// 488 / 578 testcases passed
    meetings.assign({{2,3}, {3,5}, {8,8}});
    sol.countDays(8, meetings);

    return 0;
}