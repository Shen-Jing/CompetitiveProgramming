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
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

const int alphabet_size{26};

struct Vertex
{
    int alphabet;
    vector<unique_ptr<Vertex>> child;
    bool exist;
    Vertex(char ch) : alphabet(ch), exist(false), child(alphabet_size)
    {
    }
};

class Trie {
 private: 
    unique_ptr<Vertex> root;

 public:
    /** Initialize your data structure here. */
    Trie()
    {
        root.reset(new Vertex('!'));
    }
    
    /** Inserts a word into the trie. */
    void insert(const string &word)
    {
        auto cur = root.get();
        for (const auto &ch : word)
        {
            auto alpha_num = ch - 'a';
            if (cur->child[alpha_num] == nullptr)
                cur->child[alpha_num].reset(new Vertex(ch));
            cur = cur->child[alpha_num].get();
        }
        cur->exist = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string &word)
    {
        auto cur = root.get();
        for (const auto &ch : word)
        {
            auto alpha_num = ch - 'a';
            if (cur->child[alpha_num] == nullptr)
                return false;
            cur = cur->child[alpha_num].get();
        }
        return cur->exist;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &word)
    {
        auto cur = root.get();
        for (const auto &ch : word)
        {
            auto alpha_num = ch - 'a';
            if (cur->child[alpha_num] == nullptr)
                return false;
            cur = cur->child[alpha_num].get();
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(void)
{
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << "\n";   // returns true
    cout << trie.search("app") << "\n";     // returns false
    cout << trie.startsWith("app") << "\n"; // returns true
    trie.insert("app");
    cout << trie.search("app") << "\n"; // returns true
    return 0;
}