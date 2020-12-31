#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
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

int source_row; // row of source (first) queen
int num_of_solutions;
constexpr int num_of_queens{8};
array<int, num_of_queens> queens_col;  // row order: column of 1st row, 2nd row...

void solve(int cur_row)
{
    // if (cur_row == num_of_queens)
    if (cur_row == source_row)
    {
        cout << " " << ++num_of_solutions << "      ";
        cout << *queens_col.cbegin() + 1;
        for (auto it = queens_col.cbegin() + 1; it != queens_col.cend(); ++it)
            cout << " " << *it + 1;
        cout << "\n";
        return;
    }

    /* Try to place queen at all possible column */
    for (int cur_col = 0; cur_col < num_of_queens; ++cur_col)
    {
        bool is_valid{true};
        /* Check with all queens' position */
        for (int prev_row = 0; prev_row < num_of_queens; ++prev_row)
        {
            int prev_col = queens_col[prev_row];
            if (prev_col != -1 && 
               (cur_col == prev_col ||
                cur_row - cur_col == prev_row - prev_col || cur_row + cur_col == prev_row + prev_col))
            {
                is_valid = false;
                break;
            }
        }

        if (!is_valid)
            continue;
        queens_col[cur_row] = cur_col;
        auto old_queens_col = queens_col;
        solve((cur_row + 1) % num_of_queens);
        queens_col = old_queens_col;
        // solve(cur_row + 1);
    }
    
}

int main(void)
{

    int num_of_datasets;
    int source_col;
    string tmp_str;

    cin >> num_of_datasets;
    while (num_of_datasets--)
    {
        getline(cin, tmp_str);
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";

        cin >> source_row >> source_col;
        --source_row, --source_col;

        num_of_solutions = 0;
        queens_col.fill(-1);
        queens_col[source_row] = source_col;
        // solve(0);
        solve((source_row + 1) % num_of_queens);
        cout << "\n";
    }

    return 0;
}