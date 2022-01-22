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

class MedianFinder
{
 public:
    MedianFinder()
    {
        
    }
    
    void addNum(int num)
    {
        if (max_heap_.empty())
        {
            max_heap_.emplace(num);
            return;
        }
        if (min_heap_.empty())
        {
            if (num <= max_heap_.top())
            {
                min_heap_.emplace(max_heap_.top());
                max_heap_.pop();
                max_heap_.emplace(num);
            }
            else
                min_heap_.emplace(num);
            return;
        }

        auto min_of_min_heap_ = min_heap_.top(),
             max_of_max_heap_ = max_heap_.top();
        if (num > min_of_min_heap_)
            min_heap_.emplace(num);
        else if (num <= max_of_max_heap_)
            max_heap_.emplace(num);

        /* Balance the both size (max heap is more than min heap at most 1) */
        if (max_heap_.size() > min_heap_.size() + 1)
        {
            min_heap_.emplace(max_heap_.top());
            max_heap_.pop();
        }
        else if (min_heap_.size() > max_heap_.size())
        {
            max_heap_.emplace(min_heap_.top());
            min_heap_.pop();
        }
    }
    
    double findMedian()
    {
        if ((max_heap_.size() + min_heap_.size()) & 1)
            return max_heap_.top();
        return (double)(max_heap_.top() + min_heap_.top()) / 2;
    }

 private:
    priority_queue<int> max_heap_;
    /* All of elements in the min heap are larger than max heap's */
    priority_queue<int, vector<int>, greater<int>> min_heap_;
};

int main(void)
{

    return 0;
}