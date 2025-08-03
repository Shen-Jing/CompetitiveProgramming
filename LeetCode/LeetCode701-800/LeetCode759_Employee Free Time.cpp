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

// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule)
    {
        return lineSweep(schedule);
    }

 private:
    vector<Interval> lineSweep(vector<vector<Interval>> &schedules)
    {
        struct Event {
            int time;
            enum class Category {
                open,
                close
            } category;
            bool operator<(Event e) const { return time < e.time; };
        };
        vector<Event> events;
        for (const auto &schedule : schedules)
        {
            for (const auto &interval : schedule)
            {
                events.emplace_back(interval.start, Event::Category::open);
                events.emplace_back(interval.end, Event::Category::close);
            }
        }
        sort(events.begin(), events.end());

        vector<Interval> results;
        int balance = 0;
        int prev = -1;
        for (const auto &e : events)
        {
            if (e.category == Event::Category::open)
            {
                ++balance;
                if (balance == 1 && prev != -1 && prev < e.time)
                {
                    results.emplace_back(prev, e.time);
                }
            }
            else if (e.category == Event::Category::close)
            {
                --balance;
                if (balance == 0)
                {
                    prev = e.time;
                }
            }
        }
        return results;
    }
};

int main(void)
{
    vector<vector<Interval>> schedule{{{1,2},{5,6}}, {{1,3}}, {{4,10}}};

    Solution sol;
    sol.employeeFreeTime(schedule);

    return 0;
}