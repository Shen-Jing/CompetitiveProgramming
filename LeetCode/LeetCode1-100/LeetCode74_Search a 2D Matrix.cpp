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
#include <unordered_map>
#include <unordered_set>
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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
    }

 private:
    bool my_binary_search(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size(), 
            cols = matrix[0].size(),
            left{0}, right{rows};
        /* Binary search each row's element */
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (matrix[mid][0] < target)
                left = mid + 1;
            else
                right = mid;
        }

        int target_row = left;
        if (target_row == rows)
            target_row = rows - 1;
        else
        {
            if (target < matrix[target_row][0])
                --target_row;
            if (target_row < 0)
                return false;
        }

        /* Binary search target row's element */
        left = 0;
        right = cols;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (matrix[target_row][mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        return (left != cols) ? (matrix[target_row][left] == target) : false;
    }
};

int main(void)
{

    return 0;
}