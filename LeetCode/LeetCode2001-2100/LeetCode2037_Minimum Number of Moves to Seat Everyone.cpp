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
    int minMovesToSeat(vector<int>& seats, vector<int>& students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int moves = 0;
        for (size_t i = 0; i < seats.size(); ++i)
            moves += abs(seats[i] - students[i]);
        return moves;
    }
};

int main(void)
{

    return 0;
}