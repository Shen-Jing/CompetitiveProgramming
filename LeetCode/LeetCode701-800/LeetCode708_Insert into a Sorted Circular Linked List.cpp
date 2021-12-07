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

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    Node* insert(Node *head, int insert_val)
    {
    }

 private:
    Node* my_insert(Node *head, int insert_val)
    {
        Node *curr(head);
        if (!curr)
        {
            head = new Node(insert_val);
            head->next = head;
            return head;
        }
        while (curr)
        {
            if (curr->val <= insert_val && insert_val <= curr->next->val)
                break;
            /* All elements are larger than inserted value, 
               and iterator reaches the end */
            if (curr->next == head)
                break;
            curr = curr->next;
        }
        Node *insert_node = new Node(insert_val);
        insert_node->next = curr->next;
        curr->next = insert_node;
        return head;
    }
};

int main(void)
{

    return 0;
}