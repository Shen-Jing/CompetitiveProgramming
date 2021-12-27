#include <algorithm>
#include <bit>
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
    int findComplement(int num)
    {
        return my_flip_bit_by_bit(num);
    }

 private:
    int my_flip_bit_by_bit(const int &num)
    {
        int todo{num};
        bitset<32> b_num(num);
        for (int i = 0; todo; ++i) 
        {
            b_num[i] = ~b_num[i];
            todo >>= 1;
        }
        return b_num.to_ulong();
    }
};

int main(void)
{

    return 0;
}