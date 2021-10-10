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