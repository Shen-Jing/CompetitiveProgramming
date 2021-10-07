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
    bool exist(vector<vector<char>> &board, string word)
    {
        rows = board.size(), cols = board[0].size();
        target_word = word;
        visited.assign(rows, vector<bool>(cols, false));
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (check_DFS(board, r, c, 0))
                    return true; 
        return false;
    }

 private:
    int rows, cols;
    string target_word;
    /* Up, Down, Left, Right */
    const array<array<int, 2>, 4> directions{ {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} };
    vector<vector<bool>> visited;

    bool out_of_bound(const int row, const int col)
    {
        if (row < 0 || row >= rows ||
            col < 0 || col >= cols)
            return true;
        return false;
    }

    bool check_DFS(vector<vector<char>> &board, int row, int col, int word_idx)
    {
        if (board[row][col] == target_word[word_idx])
        {
            if (word_idx == target_word.length() - 1)
                return true;
        }
        else
            return false;

        visited[row][col] = true;
        for (const auto &dir : directions)
        {
            int next_row = row + dir[0], next_col = col + dir[1];
            if (!out_of_bound(next_row, next_col) && !visited[next_row][next_col] && 
                 check_DFS(board, next_row, next_col, word_idx + 1))
            {
                return true;
            }
        }
        visited[row][col] = false;
        return false;
    }
};

int main(void)
{
    Solution sol;

    vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    sol.exist(board, "ABCB");

    board.assign({{'C','A','A'},{'A','A','A'},{'B','C','D'}});
    sol.exist(board, "AAB");

    return 0;
}