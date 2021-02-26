#include <boost/algorithm/string.hpp>

void split(vector<string> &result, string &target, string_view &delim)
{
    boost::split(result, target, boost::is_any_of(delim));
}