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

int source_col; // row of source (first) queen
int num_of_solutions;
constexpr int num_of_queens{8};
array<int, num_of_queens> queens_row;  // column order: row of 1st column, 2nd column...

void solve(int cul_col)
{
    if (cul_col == source_col)
        ++cul_col;
    if (cul_col == num_of_queens)
    {
        ++num_of_solutions;
        if (num_of_solutions < 10)
            cout << " ";
        cout << num_of_solutions << "      ";
        cout << *queens_row.cbegin() + 1;
        for (auto it = queens_row.cbegin() + 1; it != queens_row.cend(); ++it)
            cout << " " << *it + 1;
        cout << "\n";
        return;
    }

    /* Try to place queen at all possible column */
    for (int cur_row = 0; cur_row < num_of_queens; ++cur_row)
    {
        bool is_valid{true};
        /* Check with all queens' position */
        for (int prev_col = 0; prev_col < num_of_queens; ++prev_col)
        {
            int prev_row = queens_row[prev_col];
            if (prev_row != -1 && 
               (cur_row == prev_row ||
                cul_col - cur_row == prev_col - prev_row || cul_col + cur_row == prev_col + prev_row))
            {
                is_valid = false;
                break;
            }
        }

        if (!is_valid)
            continue;
        queens_row[cul_col] = cur_row;
        auto old_queens_col = queens_row;
        // solve((cur_row + 1) % num_of_queens);
        solve(cul_col + 1);
        queens_row = old_queens_col;
    }
    
}

int main(void)
{

    int num_of_datasets;
    int source_row;
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
        queens_row.fill(-1);
        queens_row[source_col] = source_row;
        solve(0);
        if (num_of_datasets)
            cout << "\n";
    }

    return 0;
}