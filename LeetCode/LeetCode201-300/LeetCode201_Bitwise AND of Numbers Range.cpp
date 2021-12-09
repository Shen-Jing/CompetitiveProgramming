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
    int rangeBitwiseAnd(int left, int right)
    {
    }

 private:
    int cmp_common_prefix(const int &left, const int &right)
    {
        bitset<32> b_left(left), b_right(right);
        for (int i = 31; i >= 1; --i)
        {
            if (b_left[i] & b_right[i])
                return pow(2, i);
        }
        return 0;
    }

    int bitand_loop(const int &left, const int &right)
    {
        int ans = left;
        for (int i = left + 1; i <= right; ++i)
            ans &= i;
        return ans;
    }
};

int main(void)
{

    return 0;
}