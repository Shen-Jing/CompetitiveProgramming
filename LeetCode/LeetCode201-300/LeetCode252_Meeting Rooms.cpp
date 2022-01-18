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
    bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        return by_sort(intervals);
    }

 private:
    bool is_intersectional(const vector<int> &interval1, const vector<int> &interval2)
    {
        if (
            (interval1[0] <= interval2[0] && interval1[1] > interval2[0]) ||
            (interval2[0] <= interval1[0] && interval2[1] > interval1[0])
           )
            return true;
        return false;
    }

    bool by_sort(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < static_cast<int>(intervals.size()) - 1; ++i)
        {
            if (is_intersectional(intervals[i], intervals[i + 1]))
                return false;
        }
        return true;
    }
};

int main(void)
{

    return 0;
}