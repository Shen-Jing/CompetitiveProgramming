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
    bool wordBreak(string s, vector<string> &word_dict)
    {
        return word_break_BFS(s, word_dict);
    }

 private:
    bool word_break_BFS(string s, vector<string> &word_dict)
    {
        queue<size_t> q;
        q.push(0);
        while (!q.empty())
        {
            auto cur_idx = q.front();
            q.pop();

            if (cur_idx == s.length())
                return true;

            for (const auto &word : word_dict)
            {
                if (cur_idx == s.find(word))
                    q.push(cur_idx + word.length());
            }
        }
        return false;
    }
};

int main(void)
{
    Solution sol;

    string s{"applepenapple"};
    vector<string> word_dict{"apple", "pen"};

    sol.wordBreak(s, word_dict);
    
    return 0;
}