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

constexpr int alphabet_size{26};

struct Vertex
{
    char ch;
    bool is_end;
    array<Vertex *, alphabet_size> child;
    Vertex(char ch) : ch(ch), is_end(false)
    {
        child.fill(nullptr);
    }
};

class Trie
{
 public:
    Vertex *root_{new Vertex('!')};

    Trie() {}

    void insert(const string &word)
    {
        Vertex *curr(root_);
        for (const auto &ch : word)
        {
            int alphabet_num = ch - 'a';
            if (!curr->child[alphabet_num])
                curr->child[alphabet_num] = new Vertex(ch);
            curr = curr->child[alphabet_num];
        }
        curr->is_end = true;
    }

    bool search(const string &word)
    {
        Vertex *curr(root_);
        for (const auto &ch : word)
        {
            int alphabet_num = ch - 'a';
            if (!curr->child[alphabet_num])
                return false;
            curr = curr->child[alphabet_num];
        }
        return curr->is_end;
    }

    bool startsWith(const string &prefix)
    {
        Vertex *curr(root_);
        for (const auto &ch : prefix)
        {
            int alphabet_num = ch - 'a';
            if (!curr->child[alphabet_num])
                return false;
            curr = curr->child[alphabet_num];
        }
        return true;
    }

 private:
};

class Solution
{
 public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        
    }
};

int main(void)
{

    return 0;
}