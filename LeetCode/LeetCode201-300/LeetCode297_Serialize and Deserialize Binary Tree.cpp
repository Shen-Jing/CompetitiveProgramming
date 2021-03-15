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
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Codec
{
 public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        ss.str("");
        ss.clear();
        sub_serialize(root);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        ss.str(data);
        ss.clear();
        auto root = new TreeNode(0);
        sub_deserialize(root->left);
        return root->left;
    }

 private:
    stringstream ss;

    void sub_serialize(TreeNode *root)
    {
        if (root)
        {
            ss << root->val << " ";
            sub_serialize(root->left);
            sub_serialize(root->right);
        }
        else
            ss << "# ";
    }

    void sub_deserialize(TreeNode *node)
    {
        string val;
        ss >> val;
        if (val == "#")
        {
            node = nullptr;
        }
        else
        {
            node = new TreeNode(stoi(val));
            sub_deserialize(node->left);
            sub_deserialize(node->right);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));;

int main(void)
{
    Codec serializer, deserializer;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    cout << serializer.serialize(root);  // 1 2 # # 3 4 # # 5 # #

    auto ans = deserializer.deserialize(serializer.serialize(root));
    return 0;
}