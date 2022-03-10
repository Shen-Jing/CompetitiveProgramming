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
    bool isStrobogrammatic(string num)
    {
        array<char, 10> strobo;
        fill(strobo.begin(), strobo.end(), 'F');
        strobo[0] = '0';
        strobo[1] = '1';
        strobo[6] = '9';
        strobo[8] = '8';
        strobo[9] = '6';

        for (int left = 0, right = num.size() - 1; left < num.size() && right >= 0; ++left, --right)
        {
            int left_num = num[left] - '0',
                right_num = num[right] - '0';
            if (strobo[left_num] == 'F' || strobo[right_num] == 'F' ||
                strobo[left_num] != num[right] || strobo[right_num] != num[left])
                return false;
        }
        return true;
    }
};

int main(void)
{

    return 0;
}