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
    /** 
     * Forward declaration of guess API.
     * @param  num   your guess
     * @return 	     -1 if num is lower than the guess number
     *			          1 if num is higher than the guess number
     *                otherwise return 0
     * int guess(int num);
     */
    int guessNumber(uint32_t n)
    {
        return binary_guess(1, n + 1);
    }

    uint32_t binary_guess(uint32_t first, uint32_t last)
    {
        while (first < last)
        {
            int mid = first + ((last - first) >> 1);
            if (guess(mid) == -1 || guess(mid) == 0)
                last = mid;
            else if (guess(mid) == 1)
                first = mid + 1;
        }
        return first;
    }
};

int guess(int num)
{
    return num;
}

int main(void)
{

    return 0;
}