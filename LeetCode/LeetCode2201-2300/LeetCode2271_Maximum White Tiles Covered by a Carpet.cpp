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
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen)
    {
        sort(tiles.begin(), tiles.end());
        int max_len{0}, last_len = tiles[0][1] - tiles[0][0] + 1, cur_len{0},
            sz = tiles.size();
        for (int i = 1; i < sz; ++i)
        {
            max_len = max(max_len, min(last_len, carpetLen));
            int cur_len = tiles[i][1] - tiles[i][0] + 1;
            /* Continuous tiles */
            if (tiles[i][0] == tiles[i - 1][1] + 1)
            {
                cur_len += last_len;
            }
            last_len = cur_len;
        }
        return max_len;
    }
};

int main(void)
{

    return 0;
}