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
    MyQueue()
    {
        
    }
    
    void push(int x)
    {
        input_stk.push(x);
    }
    
    int pop()
    {
        int data = peek();
        output_stk.pop();
        return data;
    }
    
    int peek()
    {
        if (output_stk.empty())
        {
            while (!input_stk.empty())
            {
                output_stk.push(input_stk.top());
                input_stk.pop();
            }
        }
        /// All the calls are guranteed to be valid => the push stack must be non-empty
        return output_stk.top();
    }
    
    bool empty()
    {
        return input_stk.empty() && output_stk.empty();
    }
 private:
    stack<int> input_stk, output_stk;
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