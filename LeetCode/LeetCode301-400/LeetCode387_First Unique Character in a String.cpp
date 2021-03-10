//static auto io = [](){
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    return nullptr;
//}();
class Solution {
public:
    int firstUniqChar(string s) {
        std::map<char, int> wrd_rcd;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!wrd_rcd.count(s[i]))
            {
                int pos = s.find(s[i], i + 1);
                if (pos == std::string::npos)
                    return i;
                wrd_rcd[s[i]] = pos;
            }
        }
        return -1;
    }
};