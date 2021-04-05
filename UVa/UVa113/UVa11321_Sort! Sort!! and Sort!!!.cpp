#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <type_traits>
#include <utility>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int main(void)
{
    int N, M;
    while (cin >> N >> M)
    {
        cout << N << " " << M << "\n";
        if (!N)
            break;
        vector<int> vec;
        vec.reserve(N);
        for (int i = 0; i < N; ++i)
        {
            int input;
            cin >> input;
            vec.emplace_back(input);
        }
        auto order = [&, M](const int &lhs, const int &rhs){
            if (lhs % M == rhs % M)
            {
                // 2 odd
                if ((lhs & 1) && (rhs & 1))
                    return lhs > rhs;
                // 2 even
                if (!(lhs & 1) && !(rhs & 1))
                    return lhs < rhs;
                // odd, even
                if (lhs & 1)
                    return true;
                return false;
            }
            return (lhs % M) < (rhs % M);
        };
        sort(vec.begin(), vec.end(), order);
        for (const auto & val : vec)
            cout << val << "\n";
    }
    return 0;
}