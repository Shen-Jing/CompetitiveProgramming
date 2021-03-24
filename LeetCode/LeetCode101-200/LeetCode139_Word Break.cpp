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
        auto len = s.length();
        vector<bool> visited(len);
        set<string> words{word_dict.begin(), word_dict.end()};
        queue<size_t> q;
        q.push(0);
        while (!q.empty())
        {
            auto start = q.front();
            q.pop();

            if (visited[start])
                continue;

            for (size_t end{start + 1}; end <= len; ++end)
            {
                if (words.find(s.substr(start, end - start)) != words.end())
                {
                    if (end == s.length())
                        return true;
                    q.push(end);
                }
            }
            visited[start] = true;
        }
        return false;
    }
};

int main(void)
{
    Solution sol;

    string s{"applepenapple"};
    vector<string> word_dict{"apple", "pen"};
    sol.wordBreak(s, word_dict);  // True

    s.assign("catsandog");
    word_dict.assign({"cats", "dog", "sand", "and", "cat"});
    sol.wordBreak(s, word_dict);  // False
    
    s.assign("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    word_dict.assign({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
    sol.wordBreak(s, word_dict);  // False or TLE
    
    return 0;
}