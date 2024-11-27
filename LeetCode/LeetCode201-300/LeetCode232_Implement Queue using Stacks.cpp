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

/// Amortized
class MyQueue {
 public:
    MyQueue() {
        
    }
    
    void push(int x) {
        push_stk.push(x);
    }
    
    int pop() {
        if (pop_stk.empty())
        {
            while (!push_stk.empty())
            {
                pop_stk.push(push_stk.top());
                push_stk.pop();
            }
        }
        /// All the calls are guranteed to be valid => the push stack must be non-empty
        int data = pop_stk.top();
        pop_stk.pop();
        return data;
    }
    
    int peek()
    {
        if (pop_stk.empty())
        {
            while (!push_stk.empty())
            {
                pop_stk.push(push_stk.top());
                push_stk.pop();
            }
            return pop_stk.top();
        }
        else
        {
            return pop_stk.top();
        }
        
    }
    
    bool empty() {
        return push_stk.empty() && pop_stk.empty();
    }
 private:
    stack<int> push_stk, pop_stk;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(void)
{

    return 0;
}