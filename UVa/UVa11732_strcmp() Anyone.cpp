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
#include <memory>
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

constexpr int kMaxNodes = 4000 * 1000 + 10;
int ans = 0;

class Trie
{
 public:
  Trie()
  {
      num_of_nodes = 1;
      alphanumerals_value = make_unique<char []>(kMaxNodes);
      sons = make_unique<int []>(kMaxNodes);
      siblings = make_unique<int []>(kMaxNodes);
      counts = make_unique<int []>(kMaxNodes);
  }
  
  void insert(const string &str)
  {
      int cur_parent = 0;
      auto len = str.length();
      for (size_t i = 0; i <= len; ++i)
      {
          int new_node = 0;
          for (int cur_node = sons[cur_parent]; cur_node; cur_node = siblings[cur_node])
          {
              if (alphanumerals_value[cur_node] == str[i])
              {
                  new_node = cur_node;
                  ans += counts[cur_node] * 2;
              }
              else
                  ans += counts[cur_node];
          }
          if (!new_node)
          {
              new_node = num_of_nodes;
              ++num_of_nodes;
              alphanumerals_value[new_node] = str[i];
              counts[new_node] = sons[new_node] = 0;
              siblings[new_node] = sons[cur_parent];
              sons[cur_parent] = new_node;
          }
          ++counts[new_node];
          cur_parent = new_node;
      }
  }

 private:
  int num_of_nodes;
  unique_ptr<char []> alphanumerals_value;
  unique_ptr<int []> sons, siblings, counts;
};

int main(void)
{
    int num_of_strings;
    for (int kase = 1; cin >> num_of_strings && num_of_strings > 0; ++kase)
    {
        string input;
        Trie trie;
        ans = 0;
        while (num_of_strings--)
        {
            cin >> input;
            trie.insert(input);
        }
        cout << "Case " << kase << ": " << ans << "\n";
    }
    return 0;
}