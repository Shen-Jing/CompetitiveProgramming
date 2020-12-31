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

int source_row, source_col; // row, col of source (first) queen
int num_of_solutions;
constexpr int num_of_queens{8};
array<int, num_of_queens> queens_col;  // row order: column of 1st row, 2nd row...

void solve(int cur_row)
{
    if (cur_row == source_row)
    {
        cout << ++num_of_solutions;
        cout << "\n";
    }

    /* Try to place queen at all possible column */
    int prev_row = (cur_row - 1 + 8) % num_of_queens;
    int prev_col = queens_col[prev_row];
    for (int cur_col = 0; cur_col < num_of_queens; ++cur_col)
    {
        if (cur_col == prev_col
         || cur_row - cur_col == prev_row - prev_col
         || cur_row + cur_col == prev_row + prev_col)
            continue;
        queens_col[cur_row] = cur_col;
        solve((cur_row + 1) % num_of_queens);
    }
    
}

int main(void)
{

    int num_of_datasets;
    string tmp_str;

    cin >> num_of_datasets;
    while (num_of_datasets--)
    {
        getline(cin, tmp_str);
        cout << "SOLN COLUMN\n";
        cout << "# 1 2 3 4 5 6 7 8\n\n";

        cin >> source_row >> source_col;
        --source_row, --source_col;

        num_of_solutions = 0;
        queens_col[source_row] = source_col;
        solve((source_row + 1) % num_of_queens);
        cout << "\n";
    }

    return 0;
}