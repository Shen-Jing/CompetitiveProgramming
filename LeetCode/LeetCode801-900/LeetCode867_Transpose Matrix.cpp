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
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(),
            cols = matrix[0].size();
        vector<vector<int>> ans(cols, vector<int>(rows, 0));
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                ans[c][r] = matrix[r][c];
        return ans;
    }
};

int main(void)
{

    return 0;
}