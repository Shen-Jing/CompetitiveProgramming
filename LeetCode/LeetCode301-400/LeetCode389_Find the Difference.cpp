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
    char findTheDifference(string source, string target)
    {
    }

 private:
    char find_the_diff_by_sorting(string source, string target)
    {
        sort(source.begin(), source.end());
        sort(target.begin(), target.end());
        for (size_t i = 0; i < source.length(); ++i)
        {
            if (source[i] != target[i])
                return target[i];
        }
        return target.back();
    }
};

int main(void)
{

    return 0;
}