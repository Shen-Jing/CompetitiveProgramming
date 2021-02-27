#include <vector>
#include <string>
#include <string_view>
#include <type_traits>
#include <boost/algorithm/string.hpp>

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