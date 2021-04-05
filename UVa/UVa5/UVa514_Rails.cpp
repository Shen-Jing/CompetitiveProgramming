#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
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
    int blocks;
    while (cin >> blocks)
    {
        cin.get();  // remove new line
        string line;
        while (getline(cin, line))
        {
            if (line[0] == '0')
            {
                cout << "\n";
                break;
            }

            istringstream ss{line};
            stack<int> s;
            int num;
            int cur_pushed{1};
            bool rnd_flag;

            for (int i = 1; i <= blocks; ++i)
            {
                ss >> num;

                while (cur_pushed <= num)
                    s.push(cur_pushed++);
                
                rnd_flag = false;
                while (!s.empty())
                {
                    if (s.top() == num)
                    {
                        rnd_flag = true;
                        s.pop();
                        break;
                    }
                    s.pop();
                }
                if (s.empty() && !rnd_flag)
                    break;
            }
            cout << (rnd_flag ? "Yes" : "No") << "\n";
        }
    }

    return 0;
}
