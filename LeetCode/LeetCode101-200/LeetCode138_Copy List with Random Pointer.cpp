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
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
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
    Node* copyRandomList(Node* head)
    {
        if (!head)
            return nullptr;
        Node *new_list, *new_cur, *old_cur;
        new_cur = new_list = new Node(0);

        vector<Node *> indices_pointer;
        vector<int> random_list;
        indices_pointer.reserve(num_of_nodes);
        random_list.reserve(num_of_nodes);
        map<Node *, int> pointer_to_index;

        old_cur = head;
        for (int i = 0; old_cur; ++i, old_cur = old_cur->next)
            pointer_to_index[old_cur] = i;

        old_cur = head;
        for (int i = 0; old_cur; ++i, old_cur = old_cur->next)
        {
            /* Copied to new list */
            auto node = new Node(old_cur->val);
            new_cur->next = node;
            new_cur = new_cur->next;
            /* Get pointer to current node */
            indices_pointer.emplace_back(node);
            /* Record the current pointer to which node index */
            if (old_cur->random)
                random_list.emplace_back(pointer_to_index[old_cur->random]);
            else
                random_list.emplace_back(-1);
        }

        new_list = new_list->next;
        new_cur = new_list;
        for (const auto &rand_idx : random_list)
        {
            if (rand_idx >= 0)
                new_cur->random = indices_pointer[rand_idx];
            else
                new_cur->random = nullptr;
            new_cur = new_cur->next;
        }

        return new_list;
    }
 private:
    const int num_of_nodes{1000};
};

int main(void)
{

    return 0;
}