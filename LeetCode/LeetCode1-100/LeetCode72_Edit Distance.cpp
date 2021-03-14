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
    int minDistance(string word1, string word2)
    {
        auto source_sz = word1.size(), target_sz = word2.size();
        vector<vector<int>> dist(source_sz + 1, vector<int>(target_sz + 1, 0));
        /* Deletion on source string */
        for (size_t r = 1; r <= source_sz; ++r)
            dist[r][0] = r;
        /* Insertion on source string */
        for (size_t c = 1; c <= target_sz; ++c)
            dist[0][c] = c;
        for (size_t r = 1; r <= source_sz; ++r)
            for (size_t c = 1; c <= target_sz; ++c)
            {
                if (word1[r - 1] == word2[c - 1])
                    dist[r][c] = dist[r - 1][c - 1];
                else
                {
                    /* Deletion or Insertion */
                    dist[r][c] = min(dist[r - 1][c] + 1, dist[r][c - 1] + 1);
                    /* or Replacement */
                    dist[r][c] = min(dist[r][c], dist[r - 1][c - 1] + 1);
                }
            }
        return dist[source_sz][target_sz];
    }
};

int main(void)
{
    Solution sol;
    sol.minDistance("intention", "execution");
    return 0;
}