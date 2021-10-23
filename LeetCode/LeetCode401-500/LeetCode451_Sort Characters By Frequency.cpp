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
    string frequencySort(string s)
    {

    }

 private:
    string hash_and_STL(string s)
    {
        unordered_map<char, int> freqencies;
        for (const auto &ch : s)
            ++freqencies[ch];
        sort(s.begin(), s.end(), [&](char a, char b) {
            return (freqencies[a] > freqencies[b]) || (freqencies[a] == freqencies[b] && a < b);
        });
        return s;
    }
};

int main(void)
{

    return 0;
}