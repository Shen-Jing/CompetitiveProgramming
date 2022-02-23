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
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
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
    Node* cloneGraph(Node* node)
    {
        return my_BFS(node);
    }

 private:
    Node* my_BFS(Node *node)
    {
        if (!node)
            return nullptr;

        int num_of_nodes{0};
        Node *first_node;
        unordered_set<Node *> seen;
        queue<Node *> Q;
        Q.emplace(node);
        while (!Q.empty())
        {
            ++num_of_nodes;
            Node *new_node = new Node(node->val);
            if (num_of_nodes == 1)
                first_node = new_node;

            Node *curr = Q.front();
            Q.pop();
            seen.emplace(curr);
            for (const auto neighbor : curr->neighbors)
            {
                new_node->neighbors.emplace_back(new Node(neighbor->val));
                if (seen.count(neighbor))
                    continue;
                Q.emplace(neighbor);
            }
        }

        return first_node;
    }
};

int main(void)
{

    return 0;
}