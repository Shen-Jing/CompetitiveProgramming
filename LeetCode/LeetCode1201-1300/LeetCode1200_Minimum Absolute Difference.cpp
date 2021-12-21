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
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
    }

 private:
    vector<vector<int>> two_pass(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int min_diff{arr.back() - arr.front()};
        for (int i = 1; i < arr.size(); ++i)
            min_diff = min(min_diff, arr[i] - arr[i - 1]);
        
        vector<vector<int>> min_diff_pairs;
        for (int i = 1; i < arr.size(); ++i)
            if (arr[i] - arr[i - 1] == min_diff)
                min_diff_pairs.push_back({arr[i - 1], arr[i]});
        
        return min_diff_pairs;
    }
};

int main(void)
{

    return 0;
}