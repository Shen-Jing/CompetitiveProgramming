#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <limits>
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

int main(void)
{
    int rows, cols;
    int cost;
    while (cin >> rows >> cols)
    {
        vector<vector<int>> mat;
        vector<vector<int>> dp(rows, vector<int>(cols, numeric_limits<int>::max() / 2));
        vector<vector<int>> path_from(rows, vector<int>(cols, 0));

        mat.reserve(rows);
        for (int r = 0; r < rows; ++r)
        {
            mat.emplace_back(vector<int>());
            mat[r].reserve(cols);
            for (int c = 0; c < cols; ++c)
            {
                int input;
                cin >> input;
                mat[r].emplace_back(input);
                if (c == 0)
                    dp[r][c] = input;
            }
        }

        for (int c = 1; c < cols; ++c)
            for (int r = 0; r < rows; ++r)
            {
                array<int, 3> row_from{-1, 0, 1};
                for (auto it = row_from.begin(); it < row_from.cend(); ++it)
                    *it = (r + *it + rows) % rows;
                sort(row_from.begin(), row_from.end());

                int min_row = 0;
                for (const auto &r_idx : row_from)
                    if (mat[r][c] + dp[r_idx][c - 1] < dp[r][c])
                    {
                        dp[r][c] = mat[r][c] + dp[r_idx][c - 1];
                        path_from[r][c] = r_idx;
                    }
            }
        
        cost = numeric_limits<int>::max();
        int min_row{0};
        for (int r = 0; r < rows; ++r)
            if (cost > dp[r][cols - 1])
            {
                cost = dp[r][cols - 1];
                min_row = r;
            }
        
        vector<int> ans{min_row};
        ans.reserve(cols);
        int col = cols;
        while (--col > 0)
        {
            ans.emplace_back(path_from[min_row][col]);
            min_row = path_from[min_row][col];
        }

        for (auto it = ans.crbegin(); it != ans.crend(); ++it)
            cout << *it + 1 << " ";
        cout << "\n" << cost << "\n";
    }
    return 0;
}