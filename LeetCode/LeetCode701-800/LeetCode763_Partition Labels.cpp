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

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    vector<int> partitionLabels(string s)
    {
        const auto len = s.length();
        array<size_t, 26> last_pos;

        for (size_t i = 0; i < len; ++i)
            last_pos[s[i] - 'a'] = i;

        vector<int> partition_lens;
        /* Range: (closed) [start, end] */
        size_t last_partition_start = 0, last_partition_end = 0;
        for (size_t i = 0; i < len; ++i)
        {
            last_partition_end = max(last_partition_end, last_pos[s[i] - 'a']);
            if (i == last_partition_end)
            {
                partition_lens.emplace_back(last_partition_end - last_partition_start + 1);
                last_partition_start = i + 1;
            }
        }
        return partition_lens;
    }
};

int main(void)
{

    return 0;
}