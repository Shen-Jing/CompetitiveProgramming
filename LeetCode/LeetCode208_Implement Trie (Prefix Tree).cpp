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

struct vertex
{
    int alphabet;
    vector<vertex *> child;
    bool exist;
    vertex(char ch) : alphabet(ch), exist(false)
    {
        child.assign(alphabet_size, nullptr);
    }
};

class Trie {
 private: 
    vertex *root;

 public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new vertex('!');
    }
    
    /** Inserts a word into the trie. */
    void insert(const string &word)
    {
        vertex *cur = root;
        for (const auto &ch : word)
        {
            auto alpha_num = ch - 'a';
            if (cur->child[alpha_num] == nullptr)
                cur->child[alpha_num] = new vertex(ch);
            cur = cur->child[alpha_num];
        }
        cur->exist = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string &word) {
        vertex *cur = root;
        for (const auto &ch : word)
        {
            auto alpha_num = ch - 'a';
            if (cur->child[alpha_num] == nullptr)
                return false;
            cur = cur->child[alpha_num];
        }
        return cur->exist;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string &prefix) {
        vertex *cur = root;
        for (const auto &ch : prefix)
        {
            auto alpha_num = ch - 'a';
            if (cur->child[alpha_num] == nullptr)
                return false;
            cur = cur->child[alpha_num];
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
    trie.search("apple");   // returns true
    trie.search("app");     // returns false
    trie.startsWith("app"); // returns true
    trie.insert("app");
    trie.search("app"); // returns true
    return 0;
}