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
    int numTrees(int n)
    {
        num_of_BSTs.fill(-1);
        return num_of_trees_top_down(n);
    }

 private:
    array<int, 20> num_of_BSTs;
    int num_of_trees_top_down(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        if (num_of_BSTs[n] != -1)
            return num_of_BSTs[n];

        int sum{0};
        for (int root_idx = 1; root_idx <= n; ++root_idx)
        {
            sum += num_of_trees_top_down(root_idx - 1) * num_of_trees_top_down(n - root_idx);
        }
        return num_of_BSTs[n] = sum;
    }
};

int main(void)
{

    return 0;
}