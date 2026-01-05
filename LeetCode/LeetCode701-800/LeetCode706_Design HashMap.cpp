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
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class MyHashMap
{
 public:
    MyHashMap()
    {
        fill(data_arr_.begin(), data_arr_.end(), list<Data>{});
    }
    
    void put(int key, int value)
    {
        int idx = key % SIZE;
        for (auto &data : data_arr_[idx])
        {
            if (data.key == key)
            {
                data.value = value;
                return;
            }
        }
        data_arr_[idx].emplace_back(key, value);
    }
    
    int get(int key)
    {
        int idx = key % SIZE;
        for (auto &data : data_arr_[idx])
        {
            if (data.key == key)
            {
                return data.value;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        int idx = key % SIZE;
        for (auto it = data_arr_[idx].begin(); it != data_arr_[idx].end(); ++it)
        {
            if (it->key == key)
            {
                data_arr_[idx].erase(it);
                return;
            }
        }
    }

 private:
    struct Data {
        int key;
        int value;
    };
    static const int SIZE = 1000;
    array<list<Data>, SIZE> data_arr_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(void)
{

    return 0;
}