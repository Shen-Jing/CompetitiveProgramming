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
    int candy(vector<int> &ratings)
    {
        return two_pass(ratings);
    }

 private:
    int two_pass(vector<int> &ratings)
    {
        vector<int> candies[2];
        for (int i = 0; i < 2; ++i)
        {
            candies[i].assign(ratings.size(), 1);
        }
        
        int sz = ratings.size();
        /// left to right
        for (int i = 1; i < sz; ++i)
        {
            if (ratings[i - 1] < ratings[i])
            {
                candies[0][i] = candies[0][i - 1] + 1;
            }
        }
        
        /// right to left
        for (int i = sz - 2; i >= 0; --i)
        {
            if (ratings[i + 1] < ratings[i])
            {
                candies[1][i] = candies[1][i + 1] + 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < sz; ++i)
        {
            sum += max(candies[0][i], candies[1][i]);
        }
        return sum;
    }
};

int main(void)
{

    return 0;
}