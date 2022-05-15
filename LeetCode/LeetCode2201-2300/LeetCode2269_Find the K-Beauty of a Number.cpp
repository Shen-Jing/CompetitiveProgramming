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
    int divisorSubstrings(int num, int k)
    {
        string str_num = to_string(num);
        int len = str_num.length(), ans{0};
        for (int i = 0; i <= len - k; ++i)
        {
            string sub_str = str_num.substr(i, k);
            int sub_num = stoi(sub_str);
            if (sub_num != 0 && num % sub_num == 0)
                ++ans;
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}