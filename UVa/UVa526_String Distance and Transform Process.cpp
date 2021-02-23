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
    for (size_t c = 1; c < edit_distance[c].size(); ++c)
        edit_distance[0][c] = c;
    for (size_t r = 1; r < edit_distance[r].size(); ++r)
        edit_distance[r][0] = r;
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
                if (!q || !t)
                    continue;
                edit_distance[q][t] = min(edit_distance[q - 1][t] + 1, edit_distance[q][t - 1] + 1);
                if (query[q] == target[t])
                    edit_distance[q][t] = min(edit_distance[q][t], edit_distance[q - 1][t - 1]);
                else
                    edit_distance[q][t] = min(edit_distance[q][t], edit_distance[q - 1][t - 1] + 1);
            }
        }
        cout << edit_distance[query_len][target_len] << "\n";
        /* Backtracking operations */
        stack<string> operations;
        for (size_t q = query_len, t = target_len; q || t; )
        {
            string oper;
            if (edit_distance[q][t] == edit_distance[q][t - 1] + 1)
            {
                oper = string("Insert ") + to_string(q) + "," + target[t];
                --t;
            }
            else if (edit_distance[q][t] == edit_distance[q - 1][t] + 1)
            {
                oper = string("Delete ") + to_string(q);
                --q;
            }
            else if (edit_distance[q][t] == edit_distance[q - 1][t - 1])
            {
                --q, --t;
                continue;
            }
            else if (edit_distance[q][t] == edit_distance[q - 1][t - 1] + 1)
            {
                oper = string("Replace ") + to_string(q) + "," + target[t];
                --q, --t;
            }
            operations.push(oper);
        }
        int oper_id = 1;
        while (!operations.empty())
        {
            cout << oper_id++ << " ";
            cout << operations.top() << "\n";
            operations.pop();
        }
        cout << "\n";
    }

    return 0;
}