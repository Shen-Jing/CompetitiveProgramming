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
        return sub_deserialize();
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

    TreeNode* sub_deserialize()
    {
        string val;
        ss >> val;
        if (val == "#")
        {
            return nullptr;
        }
        else
        {
            auto root = new TreeNode(stoi(val));
            root->left = sub_deserialize();
            root->right = sub_deserialize();
            return root;
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