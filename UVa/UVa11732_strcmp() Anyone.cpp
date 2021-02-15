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

constexpr int kMaxNodes = 4000 * 1000 + 10;
int ans = 0;

class Trie
{
 public:
  int alphabet_size;
  
  Trie(int alphabet_size = 26)
  {
      num_of_nodes = 0;
      sons[0] = siblings[0] = counts[0] = 0;
  }
  
  constexpr int insert(const string &str)
  {
      int cur_parent = 0;
      auto len = str.length();
      for (size_t c = 0; c <= len; ++c)
      {
          int new_node = 0;
          for (int cur_node = sons[cur_parent]; cur_node; cur_node = siblings[cur_node])
          {
              if (alphanumerals_value[cur_node] == str[c])
              {
                  new_node = cur_node;
                  ans += counts[cur_node] * 2;
              }
              else
                  ans += counts[cur_node];
          }
          if (!new_node)
          {
              ++num_of_nodes;
              new_node = num_of_nodes;
              alphanumerals_value[new_node] = str[c];
              counts[new_node] = sons[new_node] = 0;
              siblings[new_node] = sons[cur_parent];
              sons[cur_parent] = new_node;
              
          }
          ++counts[new_node];
          cur_parent = new_node;
      }
  }
 private:
  char alphanumerals_value[kMaxNodes];
  int sons[kMaxNodes], siblings[kMaxNodes], counts[kMaxNodes];
  int num_of_nodes;
};

int main(void)
{
    int num_of_strings;
    while (cin >> num_of_strings)
    {
        string input;
        Trie trie;
        while (num_of_strings--)
        {
            cin >> input;
            trie.insert(input);
        }
    }



    return 0;
}