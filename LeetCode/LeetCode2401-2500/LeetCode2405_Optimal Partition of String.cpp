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
    int partitionString(string s)
    {
        return greedy(s);
    }

 private:
    int greedy(const string &s)
    {
        array<int, 26> letters_occurencies;
        fill(letters_occurencies.begin(), letters_occurencies.end(), 0);

        int cnt_partitions = 1;
        for (int i = 0; i < s.length(); ++i)
        {
            int char_ival = s[i] - 'a';
            if (letters_occurencies[char_ival] != 0)
            {
                ++cnt_partitions;
                fill(letters_occurencies.begin(), letters_occurencies.end(), 0);
            }

            ++letters_occurencies[char_ival];
        }

        return cnt_partitions;
    }
};

int main(void)
{

    return 0;
}