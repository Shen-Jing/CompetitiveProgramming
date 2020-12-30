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
int num_of_queens;
int num_of_solutions;

void solve(int cur_row)
{
    if (cur_row == source_row)
    {
        cout << ++num_of_solutions;
        cout << "\n";
    }

    /* Try to place queen at all possible column */
    for (int cur_col = 0; cur_col < num_of_queens; ++cur_col)
    {
        if (cur_col == source_col
         || cur_row - cur_col == source_row - source_col
         || cur_row + cur_col == source_row + source_col)
            continue;
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
        solve(source_row + 1);
        cout << "\n";
    }

    return 0;
}