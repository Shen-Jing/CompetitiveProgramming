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

class Solution
{
 public:
    static constexpr auto k_max{9};

    Solution()
    {
        block_size = static_cast<int>(sqrt(k_max));
    }

    bool get_input(vector<vector<char>> &board)
    {
        for (size_t i = 0; i < k_max; ++i)
            for (auto &ch : board[i])
                if (!(cin >> ch))
                   return false;
        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board) 
    {
        array<bool, k_max> roll_call;
        /* Check row */
        for (size_t r = 0; r < k_max; ++r)
        {
            fill_n(roll_call.begin(), k_max, false);
            for (size_t c = 0; c < k_max; ++c)
            {
                if (board[r][c] < '1' || board[r][c] > '9')
                    continue;
                auto value = board[r][c] - '0' - 1;
                if (roll_call[value])
                    return false;
                roll_call[value] = true;
            }
        }
        /* Check column */
        for (size_t c = 0; c < k_max; ++c)
        {
            fill_n(roll_call.begin(), k_max, false);
            for (size_t r = 0; r < k_max; ++r)
            {
                if (board[r][c] < '1' || board[r][c] > '9')
                    continue;
                auto value = board[r][c] - '0' - 1;
                if (roll_call[value])
                    return false;
                roll_call[value] = true;
            }
        }
        /* Check small board */
        vector<vector<int>> indices;
        for (int i = 0; i < block_size; ++i)
        {
            vector<int> index(3);
            iota(index.begin(), index.end(), block_size * i);
            indices.emplace_back(index);
        }
        /* {0, 1, 2}, {3, 4, 5}, {6, 7, 8} */
        for (const auto rows : indices)
        {
            for (const auto cols : indices)
            {
                fill_n(roll_call.begin(), k_max, false);
                for (const auto r : rows)
                    for (const auto c : cols)
                    {
                        if (board[r][c] < '1' || board[r][c] > '9')
                            continue;
                        auto value = board[r][c] - '0' - 1;
                        if (roll_call[value])
                            return false;
                        roll_call[value] = true;
                    }
            }
        }
        return true;
    }

  private:
    int block_size;
};

int main(void)
{
    Solution sol;
    vector<vector<char>> board(Solution::k_max, vector<char>(Solution::k_max, '0'));
    while (sol.get_input(board))
    {
        cout << sol.isValidSudoku(board) << "\n";
    }
    return 0;
}