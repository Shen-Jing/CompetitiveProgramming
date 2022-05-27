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

bool knows(int a, int b);

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

/* The knows API is defined for you.
      bool knows(int a, int b); */
class Solution
{
 public:
    int findCelebrity(int n) 
    {

    }

 private:
    int brute_force(const int &n) 
    {
        vector<vector<int>> adj_mat(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
            adj_mat[i][i] = 1;
        for (int src = 0; src < n; ++src)
        {
            for (int dst = 0; dst < n; ++dst)
            {
                if (knows(src, dst))
                    adj_mat[src][dst] = 1;
            }
        }

        for (int src = 0; src < n; ++src)
        {
            int num_of_knows = 0;
            for (int other = 0; other < n; ++other)
            {
                if (adj_mat[src][other])
                    ++num_of_knows;
            }

            /* Possible celebrity */
            if (num_of_knows == 1)
            {
                num_of_knows = 0;
                for (int other = 0; other < n; ++other)
                {
                    if (adj_mat[other][src])
                        ++num_of_knows;
                }

                if (num_of_knows == n)
                    return src;
            }
        }

        return -1;
    }
};

int main(void)
{

    return 0;
}