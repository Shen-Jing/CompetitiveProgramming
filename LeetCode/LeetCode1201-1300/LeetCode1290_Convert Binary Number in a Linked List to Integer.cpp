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
#include "utils.hpp"

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    int getDecimalValue(ListNode *head)
    {
        return my_bitset(head);
    }

 private:
    int my_bitset(ListNode *head)
    {
        bitset<32> b;
        ListNode *curr(head);
        int n{0};
        while (curr)
        {
            b[n++] = curr->val;
            curr = curr->next;
        }

        for (int i = 0; i < n / 2; ++i)
        {
            bool tmp = b[i];
            b[i] = b[(n - 1) - i];
            b[(n - 1) - i] = tmp;
        }
        return b.to_ullong();
    }
};

int main(void)
{

    return 0;
}