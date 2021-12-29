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

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    Node* connect(Node *root)
    {}

 private:
    /* Increment the level */
    Node* BFS_pair_method(Node *root)
    {
        if (!root)
            return nullptr;

        queue<pair<Node *, int>> nodes_q;
        nodes_q.emplace(root, 0);
        while (!nodes_q.empty())
        {
            auto curr = nodes_q.front();
            nodes_q.pop();
            if (curr.first->left)
                nodes_q.emplace(curr.first->left, curr.second + 1);
            if (curr.first->right)
                nodes_q.emplace(curr.first->right, curr.second + 1);
            if (!nodes_q.empty() && 
                 nodes_q.front().second == curr.second)
                curr.first->next = nodes_q.front().first;
        }
        return root;
    }
};

int main(void)
{

    return 0;
}