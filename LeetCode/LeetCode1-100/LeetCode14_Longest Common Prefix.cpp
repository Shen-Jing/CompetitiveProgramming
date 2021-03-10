static auto io = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        for (int length = strs[0].size(); length >= 1; --length)
        {
            std::string ans = strs[0].substr(0, length);
            int i = 1;
            for ( ; i < strs.size(); ++i)
            {
                if (strs[i].find(ans) != 0)
                    break;
            }
            if (i == strs.size())
                return ans;
        }
        return "";
    }
};