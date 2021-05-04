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
    Solution()
    {
        int max_num{100000};
        bits_counts_.resize(max_num + 1);
        prebuild_table(max_num);
    }

    vector<int> countBits(int num)
    {
        return {bits_counts_.begin(), bits_counts_.begin() + num + 1};
    }

 private:
    vector<int> bits_counts_;

    void prebuild_table(const int &num)
    {
        for (uint32_t i = 1; i <= num; ++i)
        {
            bitset<32> b(i);
            bits_counts_[i] = b.count();
        }
    }
};

int main(void)
{

    return 0;
}