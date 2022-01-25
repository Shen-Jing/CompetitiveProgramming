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
    int longestStrChain(vector<string> &words)
    {
    }

 private:
    int bottom_up(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const auto &lhs, const auto &rhs){
            return lhs.length() < rhs.length();
        });
        map<string, int> word_chain_len;
        for (const auto &word : words)
            word_chain_len[word] = 1;
        for (int i = 1; i < words.size(); ++i)
        {
            for (int removed_idx = 0; removed_idx < words[i].length(); ++removed_idx)
            {
                auto new_word = words[i].substr(0, removed_idx - 0)
                              + words[i].substr(removed_idx + 1, words[i].length() - (removed_idx + 1));
                word_chain_len[words[i]] = max(word_chain_len[words[i]],
                                               word_chain_len[new_word] + 1);
            }
        }
        return max_element(word_chain_len.begin(), word_chain_len.end(), [](const auto &lhs, const auto &rhs){
                  return lhs.second < rhs.second;
               })->second;
    }
};

int main(void)
{
    Solution sol;

    vector<string> words{"xbc","pcxbcf","xb","cxbc","pcxbc", "pcxba"};
    sol.longestStrChain(words);

    return 0;
}