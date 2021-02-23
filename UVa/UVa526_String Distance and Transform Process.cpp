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
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int main(void)
{
    // char query[80], target[80];
    string query, target;
    constexpr int k_max_str_size{80};
    array<array<int, k_max_str_size>, k_max_str_size> edit_distance;
    while (cin >> query)
    {
        cin >> target;

        auto query_len = query.length();
        auto target_len = target.length();
        query = string(" ") + query;
        target = string(" ") + target;
        for (size_t q = 0; q <= query_len; ++q)
        {
            for (size_t t = 0; t <= target_len; ++t)
            {
                if (!q && !t)
                    continue;
                edit_distance[q][t] = min(edit_distance[q - 1][t] + 1, edit_distance[q][t - 1] + 1);
                if (query[q] == target[t])
                    edit_distance[q][t] = min(edit_distance[q][t], edit_distance[q - 1][t - 1]);
                else
                    edit_distance[q][t] = min(edit_distance[q][t], edit_distance[q - 1][t - 1] + 1);
            }
        }
        cout << edit_distance[query_len][target_len] << "\n";
    }

    return 0;
}