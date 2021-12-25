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

class Solution
{
 public:
    int evalRPN(vector<string> &tokens)
    {
        return use_stack(tokens);
    }

 private:
    int use_stack(const vector<string> &tokens)
    {
        unordered_set<string> operators{"+", "-", "*", "/"};
        stack<int> stk_operands;
        stack<char> stk_operators;
        for (const auto token : tokens)
        {
            if (operators.count(token))
            {
                int first_operand, second_operand, result;
                second_operand = stk_operands.top();
                stk_operands.pop();
                first_operand = stk_operands.top();
                stk_operands.pop();

                switch (token[0])
                {
                    case '+':
                        result = first_operand + second_operand;
                        break;
                    case '-':
                        result = first_operand - second_operand;
                        break;
                    case '*':
                        result = first_operand * second_operand;
                        break;
                    case '/':
                        result = first_operand / second_operand;
                        break;
                }
                stk_operands.emplace(result);
            }
            else
                stk_operands.emplace(stoi(token));
        }
        return stk_operands.top();
    }
};

int main(void)
{

    return 0;
}