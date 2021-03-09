#include <vector>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <boost/algorithm/string.hpp>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int value = 0, ListNode *next = nullptr) : val(value), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Serializer
{
 public:
    std::string serialize(ListNode *list)
    {
    }

    std::string serialize(TreeNode *root)
    {
    }

    /* Assume:
       - list: empty (nullptr)
       - Data example: 2 4 3
    */
    void deserialize(std::string data, ListNode *list)
    {
        std::istringstream iss(data);
        ListNode *cur = list = new ListNode();
        int value;
        while (iss >> value)
        {
            cur->next = new ListNode(value);
            cur = cur->next;
        }
        list = list->next;
    }

    /* Assume:
       - list: empty (nullptr)
       - Data example: [1,2,3,null,null,4,5]
    */
    void deserialize(std::string data, TreeNode *root)
    {

    }
};

// template <typename T>
// void split(std::vector<T> &tokens, std::string &target, std::string &delim)
void split(std::vector<std::string> &tokens, std::string &target, std::string &delim)
{
    std::vector<std::string> split_result;
    boost::split(split_result, target, boost::is_any_of(delim));

    // if (std::is_integral<T>::value)
    // {
    //     for (auto &&token : split_result)
    //         tokens.emplace_back(stoi(token));
    // }
    // else
    // {
        tokens = std::move(split_result);
//     }
}