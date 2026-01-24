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
#include <random>
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

class RandomizedSet
{
 public:
    RandomizedSet()
    {
        
    }
    
    bool insert(int val)
    {
        if (data_positions_.contains(val))
            return true;
        data_arr_.emplace_back(val);
        data_positions_[val] = prev(data_arr_.end());
        return true;
    }
    
    bool remove(int val)
    {
        if (!data_positions_.contains(val))
            return false;
        /// Swap & Pop
        swap(*data_positions_[val], data_arr_.back());
        data_arr_.pop_back();
        data_positions_.erase(val);
        return true;
    }
    
    int getRandom()
    {
        thread_local std::mt19937 gen(random_device{}());
        uniform_int_distribution<int> dis(0, data_arr_.size() - 1);
        return data_arr_[dis(gen)];
    }

 private:
    vector<int> data_arr_;
    unordered_map<int, decltype(data_arr_)::iterator> data_positions_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */