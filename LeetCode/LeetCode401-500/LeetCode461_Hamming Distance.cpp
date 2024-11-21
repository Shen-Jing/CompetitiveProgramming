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
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
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
    int hammingDistance(int x, int y)
    {
        return trick(x, y);
    }

 private:
    /// Brian Kernighan's Algorithm
    int trick(const int& x, const int& y)
    {
        int diff_num = x ^ y;
        int cnt_bit1 = 0;
        while (diff_num)
        {
            ++cnt_bit1;
            diff_num = diff_num & (diff_num - 1);
        }
        return cnt_bit1;
    }
};

int main(void)
{

    return 0;
}