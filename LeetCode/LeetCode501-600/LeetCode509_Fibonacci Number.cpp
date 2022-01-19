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
    int fib(int n)
    {
        fib_memo_.fill(-1);
        return fib_top_down(n);
        return fib_bottom_up(n);
    }

 private:
    inline static const int kN{30 + 1};
    array<int, kN> fib_memo_;
    int fib_top_down(const int &n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        if (fib_memo_[n] != -1)
            return fib_memo_[n];
        return fib_memo_[n] = fib_top_down(n - 1) + fib_top_down(n - 2);
    }

    int fib_bottom_up(const int &n)
    {
        fib_memo_[0] = 0;
        fib_memo_[2] = fib_memo_[1] = 1;

        for (int i = 3; i <= n; ++i)
            fib_memo_[i] = fib_memo_[i - 1] + fib_memo_[i - 2];
        return fib_memo_[n];
    }
};

int main(void)
{

    return 0;
}