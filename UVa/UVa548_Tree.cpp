#include<algorithm>
#include<iostream>
#include<limits>
#include<string>
#include<sstream>
#include<vector>

struct Node
{
    bool have_value;
    int value;
    Node *left, *right;
    Node(bool b = false, int val = -1, Node *l = nullptr, Node *r = nullptr): have_value(b), value(val), left(l), right(r) { };
};

void parse_line2list(std::string line, std::vector<int> &vec)
{
    std::stringstream ss(line);
    int value;
    while (ss >> value)
        vec.emplace_back(value);
}

Node* build_tree(const std::vector<int> &in, std::size_t in_l, std::size_t in_r, const std::vector<int> &post, std::size_t post_l, std::size_t post_r)
{
    if (in_l >= in_r)
        return nullptr;
    Node *root = new Node(true, post[post_r - 1]);
    std:size_t root_idx = std::find(in.begin() + in_l, in.begin() + in_r, root->value) - in.begin();
    /* left subtree */
    root->left = build_tree(in, in_l, root_idx, post, post_l, post_l + root_idx - in_l);
    /* right subtree */
    root->right = build_tree(in, root_idx + 1, in_r, post, post_l + root_idx - in_l, post_r - 1);
    return root;
}

void print_post(Node *r)
{
    if (!r)
        return;
    print_post(r->left);
    print_post(r->right);
    std::cout << r->value << " ";
}

void dfs(Node *r, int &min_sum, int cur_sum, int &leaf_val)
{
    if (!r)
        return;
    cur_sum += r->value;
    if (!r->left && !r->right)
    {
        if (cur_sum < min_sum)
        {
            min_sum = cur_sum;
            leaf_val = r->value;
        }
    }
    dfs(r->left, min_sum, cur_sum, leaf_val);
    dfs(r->right, min_sum, cur_sum, leaf_val);
}

int main(void)
{
    std::string input;
    while (getline(std::cin, input))
    {
        std::vector<int> line_in, line_post;
        // inorder 
        parse_line2list(input, line_in);
        // postorder
        getline(std::cin, input);
        parse_line2list(input, line_post);
        // range of index: [left, right) not [left, right]
        Node *root = build_tree(line_in, 0, line_in.size(), line_post, 0, line_post.size());
        // print_post(root);
        int min_sum = std::numeric_limits<int>::max();
        int ans = root->value;
        dfs(root, min_sum, 0, ans);
        std::cout << ans << std::endl;
    }
}