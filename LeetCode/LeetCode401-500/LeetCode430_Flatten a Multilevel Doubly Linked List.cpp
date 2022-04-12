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

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    Node* flatten(Node* head)
    {
        Node *curr{head};
        while (curr)
        {
            Node *old_next = curr->next;
            if (curr->child)
            {
                Node *new_next = flatten(curr->child);
                curr->next = new_next;
                new_next->prev = curr;
                curr->child = nullptr;
            }
            curr = old_next;
        }
        return head;
    }
};

int main(void)
{

    return 0;
}