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

class MinStack
{
 public:
    /** initialize your data structure here. */
    MinStack()
    {
        
    }
    
    void push(int val)
    {
        data_stack.push(val);
        if (min_stack.empty() || val <= getMin())
            min_stack.push(val);
    }
    
    void pop()
    {
        if (data_stack.top() == getMin())
            min_stack.pop();
        data_stack.pop();
    }
    
    int top()
    {
        return data_stack.top();
    }
    
    int getMin()
    {
        return min_stack.top();
    }

 private:
    stack<int> data_stack, min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(void)
{

    return 0;
}