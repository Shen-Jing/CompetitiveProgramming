#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdint>
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
    int earliestAcq(vector<vector<int>> &logs, int n)
    {
        sort(logs.begin(), logs.end(), [](const auto &a, const auto &b){
            return a[0] < b[0];
        });
        for (const auto &log : logs)
        {
            // 1 <= n <= 100
            int8_t p1 = log[1], p2 = log[2];
            int8_t g1 = FIND_RESULT::NOT_YET, g2 = FIND_RESULT::NOT_YET;
            merge_group(p1, p2, g1, g2);
            if (check(n))
                return log[0];
        }
        return -1;
    }
 private:
    vector<pair<int, pair<int, int>>> logs_;
    vector<unordered_set<int>> friends_group_;
    enum FIND_RESULT : int8_t {
        NOT_FOUND = -1,
        NOT_YET = -2
    };
    void find_group(const uint8_t &p_id, int8_t &g_id)
    {
        if (g_id == FIND_RESULT::NOT_FOUND)
        {
            return;
        }
        for (size_t i = 0; i < friends_group_.size(); ++i)
        {
            const auto g = friends_group_[i];
            if (g.find(p_id) != g.end())
            {
                g_id = i;
                return;
            }
        }
        g_id = FIND_RESULT::NOT_FOUND;
    }
    /// Assume the size of group 1 > group 2's
    /// Merge the smaller group into the larger group (merge group 2 into group 1)
    void merge_group(const int8_t &p1, const int8_t &p2,
                     int8_t &g1, int8_t &g2)
    {
        // Result
        //  -1: Not found
        //  -2: Not yet
        find_group(p1, g1),
        find_group(p2, g2);
        // Create a new group
        if (g1 == FIND_RESULT::NOT_FOUND && g2 == FIND_RESULT::NOT_FOUND)
        {
            unordered_set<int> new_group{p1, p2};
            friends_group_.emplace_back(new_group);
        }
        else if (g1 != FIND_RESULT::NOT_FOUND && g2 != FIND_RESULT::NOT_FOUND)
        {
            if (friends_group_[g1].size() < friends_group_[g2].size())
                return merge_group(p2, p1, g2, g1);
            if (g1 == g2)
                return;
            /// Get all frineds and merge into larger group
            auto &larger_group = friends_group_[g1];
            for (const auto &f : friends_group_[g2])
            {
                larger_group.emplace(f);
            }
            auto it = friends_group_.begin() + g2;
            friends_group_.erase(it);
        }
        else  // One of them is found but the other is not
        {
            // Assume p1 has group but p2 not
            if (g1 == FIND_RESULT::NOT_FOUND)
            {
                return merge_group(p2, p1, g2, g1);
            }
            auto &larger_group = friends_group_[g1];
            larger_group.emplace(p2);
        }
    }

    bool check(const int &n)
    {
        if (friends_group_.size() == 1 && friends_group_[0].size() == n)
            return true;
        return false;
    }
};

int main(void)
{
    vector<vector<int>> data = {{20190101,0,1},{20190104,3,4},{20190107,2,3},{20190211,1,5},{20190224,2,4},{20190301,0,3},{20190312,1,2},{20190322,4,5}};
    Solution sol;
    sol.earliestAcq(data, 6);
    return 0;
}