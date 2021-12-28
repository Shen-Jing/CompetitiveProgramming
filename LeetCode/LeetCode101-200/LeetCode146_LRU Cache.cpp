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

class LRUCache 
{
 public:
    LRUCache(int capacity) : capacity_(capacity) { }
    
    int get(const int &key)
    {
        // print("get", key);
        if (key_to_val_.count(key))
        {
            key_to_iter_[key] = update(key);
            return key_to_val_[key];
        }
        return -1;
    }
    
    void put(const int &key, const int &value)
    {
        // print("put", key, value);
        /* If the key is not in the cache,
           and the cache has no more space to insert. */
        if (!key_to_val_.count(key) && key_to_val_.size() == capacity_)
        {
            /* Remove LRU element */
            const auto removed_key = keys_.front();
            keys_.pop_front();
            key_to_val_.erase(removed_key);
            key_to_iter_.erase(removed_key);
        }

        key_to_val_[key] = value;
        /* Update priority */
        key_to_iter_[key] = update(key);
    }

 private:
    int capacity_;
    unordered_map<int, int> key_to_val_;
    unordered_map<int, list<int>::iterator> key_to_iter_;
    list<int> keys_;

    void print(string cmd, int key, int value = -1)
    {
        cout << "CMD: " << cmd << "(" << key;
        if (cmd == "put")
            cout << ", " << value;
        cout << ")\n";

        for (const auto &key : keys_)
            cout << "{" << key << ", " << key_to_val_[key] << "} ";
        cout << "\n";
    }

    auto update(const int &key) -> decltype(keys_)::iterator
    {
        /* If the key exists in cache, remove it
          (we will reinsert it later) */
        if (key_to_iter_.count(key))
        {
            auto removed_key_iter = key_to_iter_[key];
            keys_.erase(removed_key_iter);
        }
        /*  (re) Insert */
        keys_.emplace_back(key);
        return prev(keys_.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(void)
{
    LRUCache lru_cache = LRUCache(2);
    // lru_cache.put(1, 1); // cache is {1=1}
    // lru_cache.put(2, 2); // cache is {1=1, 2=2}
    // lru_cache.get(1);    // return 1
    // lru_cache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    // lru_cache.get(2);    // returns -1 (not found)
    // lru_cache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    // lru_cache.get(1);    // return -1 (not found)
    // lru_cache.get(3);    // return 3
    // lru_cache.get(4);    // return 4

    /* 14 / 22 test cases passed. */
    lru_cache = LRUCache(10);
    lru_cache.put(10, 13);
    lru_cache.put(3,17);
    lru_cache.put(6,11);
    lru_cache.put(10,5);
    lru_cache.put(9,10);

    lru_cache.get(13);

    lru_cache.put(2,19);

    lru_cache.get(2);
    lru_cache.get(3);

    lru_cache.put(5,25);

    lru_cache.get(8);

    lru_cache.put(9,22);  // The first wrong part
    lru_cache.put(5,5);
    lru_cache.put(1,30);

    lru_cache.get(11);

    lru_cache.put(9,12);

    lru_cache.get(7);
    lru_cache.get(5);
    lru_cache.get(8);
    lru_cache.get(9);

    lru_cache.put(4,30);
    lru_cache.put(9,3);

    lru_cache.get(9);
    lru_cache.get(10);
    lru_cache.get(10);

    lru_cache.put(6,14);
    lru_cache.put(3,1);

    lru_cache.get(3);

    lru_cache.put(10,11);

    lru_cache.get(8);

    lru_cache.put(2,14);

    lru_cache.get(1);
    lru_cache.get(5);
    lru_cache.get(4);

    lru_cache.put(11,4);
    lru_cache.put(12,24);
    lru_cache.put(5,18);

    lru_cache.get(13);

    lru_cache.put(7,23);

    lru_cache.get(8);
    lru_cache.get(12);

    lru_cache.put(3,27);
    lru_cache.put(2,12);

    lru_cache.get(5);

    lru_cache.put(2,9);
    lru_cache.put(13,4);
    lru_cache.put(8,18);
    lru_cache.put(1,7);

    lru_cache.get(6);

    lru_cache.put(9,29);
    lru_cache.put(8,21);

    lru_cache.get(5);

    lru_cache.put(6,30);
    lru_cache.put(1,12);

    lru_cache.get(10);

    lru_cache.put(4,15);
    lru_cache.put(7,22);
    lru_cache.put(11,26);
    lru_cache.put(8,17);
    lru_cache.put(9,29);

    lru_cache.get(5);

    lru_cache.put(3,4);
    lru_cache.put(11,30);

    lru_cache.get(12);

    lru_cache.put(4,29);

    lru_cache.get(3);
    lru_cache.get(9);
    lru_cache.get(6);

    lru_cache.put(3,4);

    lru_cache.get(1);
    lru_cache.get(10);

    lru_cache.put(3,29);
    lru_cache.put(10,28);
    lru_cache.put(1,20);
    lru_cache.put(11,13);

    lru_cache.get(3);

    lru_cache.put(3,12);
    lru_cache.put(3,8);
    lru_cache.put(10,9);
    lru_cache.put(3,26);

    lru_cache.get(8);
    lru_cache.get(7);
    lru_cache.get(5);

    lru_cache.put(13,17);
    lru_cache.put(2,27);
    lru_cache.put(11,15);

    lru_cache.get(12);

    lru_cache.put(9,19);
    lru_cache.put(2,15);
    lru_cache.put(3,16);

    lru_cache.get(1);

    lru_cache.put(12,17);
    lru_cache.put(9,1);
    lru_cache.put(6,19);

    lru_cache.get(4);  // -1
    lru_cache.get(5);
    lru_cache.get(5);

    lru_cache.put(8,1);
    lru_cache.put(11,7);
    lru_cache.put(5,2);
    lru_cache.put(9,28);

    lru_cache.get(1);

    lru_cache.put(2,2);
    lru_cache.put(7,4);
    lru_cache.put(4,22);
    lru_cache.put(7,24);
    lru_cache.put(9,26);
    lru_cache.put(13,28);
    lru_cache.put(11,26);

    return 0;
}