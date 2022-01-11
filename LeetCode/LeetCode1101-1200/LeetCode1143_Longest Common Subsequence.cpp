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
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // memo.assign(text1.length(), vector<int>(text2.length(), -1));
        vector<vector<int>> memo_tmp(text1.length() + 1, vector<int>(text2.length() + 1));
        for (int i1 = 0; i1 < text1.length(); ++i1)
            for (int i2 = 0; i2 < text2.length(); ++i2)
                memo_tmp[i1][i2] = -1;
        return LCS_top_down_Solution(memo_tmp, text1, 0, text2, 0);
        return LCS_top_down(text1, text1.length() - 1, text2, text2.length() - 1);
        return LCS_bottom_up(text1, text2);
    }

 private:
    vector<vector<int>> memo;
    int LCS_top_down(string text1, int idx1, string text2, int idx2)
    {
        if (idx1 == -1 || idx2 == -1)
            return 0;
        auto &memo_ref = memo[idx1][idx2];
        if (memo_ref != -1)
            return memo_ref;
        if (text1[idx1] != text2[idx2])
            return memo_ref = max(LCS_top_down(text1, idx1 - 1, text2, idx2), LCS_top_down(text1, idx1, text2, idx2 - 1));
        return memo_ref = 1 + LCS_top_down(text1, idx1 - 1, text2, idx2 - 1);
    }

    int LCS_top_down_Solution(vector<vector<int>> memo_tmp, string text1, int idx1, string text2, int idx2)
    {
        auto &memo_ref = memo_tmp[idx1][idx2];
        if (memo_ref != -1)
            return memo_ref;
        if (text1[idx1] != text2[idx2])
            return memo_ref = max(LCS_top_down_Solution(memo_tmp, text1, idx1 + 1, text2, idx2), LCS_top_down_Solution(memo_tmp, text1, idx1, text2, idx2 + 1));
        return memo_ref = 1 + LCS_top_down_Solution(memo_tmp, text1, idx1 + 1, text2, idx2 + 1);
    }

    int LCS_bottom_up(const string &t1, const string &t2)
    {
        auto len1 = t1.length(), len2 = t2.length();
        vector<vector<int>> LCS_length(len1, vector<int>(len2, 0));

        /* Init */
        bool has_common{false};
        for (size_t r = 0; r < len1; ++r)
            if (t1[r] == t2[0] || has_common)
            {
                LCS_length[r][0] = 1;
                has_common = true;
            }
        for (size_t c = 0; c < len2; ++c)
            if (t1[0] == t2[c] || has_common)
            {
                LCS_length[0][c] = 1;
                has_common = true;
            }

        for (size_t r = 1; r < len1; ++r)
            for (size_t c = 1; c < len2; ++c)
            {
                if (t1[r] == t2[c])
                    LCS_length[r][c] = LCS_length[r - 1][c - 1] + 1;
                else
                    LCS_length[r][c] = max(LCS_length[r - 1][c], LCS_length[r][c - 1]);
            }
        return LCS_length[len1 - 1][len2 - 1];
    }
};

int main(void)
{
    Solution sol;

    string t1{"abcde"}, t2{"ace"};
    sol.longestCommonSubsequence(t1, t2);

    t1 = string("bsbininm"), t2 = string("jmjkbkjkv");
    sol.longestCommonSubsequence(t1, t2);

    t1 = string("oxcpqrsvwf"), t2 = string("shmtulqrypy");
    sol.longestCommonSubsequence(t1, t2);

    t1 = string("fcvafurqjylclorwfoladwfqzkbebslwnmpmlkbezkxoncvwhstwzwpqxqtyxozkpgtgtsjobujezgrkvevklmludgtyrmjaxyputqbyxqvupojutsjwlwluzsbmvyxifqtglwvcnkfsfglwjwrmtyxmdgjifyjwrsnenuvsdedsbqdovwzsdghclcdexmtsbexwrszihcpibwpidixmpmxshwzmjgtadmtkxqfkrsdqjcrmxkbkfoncrcvoxuvcdytajgfwrcxivixanuzerebuzklyhezevonqdsrkzetsrgfgxibqpmfuxcrinetyzkvudghgrytsvwzkjulmhanankxqfihenuhmfsfkfepibkjmzybmlkzozmluvybyzsleludsxkpinizoraxonmhwtkfkhudizepyzijafqlepcbihofepmjqtgrsxorunshgpazovuhktatmlcfklafivivefyfubunszyvarcrkpsnglkduzaxqrerkvcnmrurkhkpargvcxefovwtapedaluhclmzynebczodwropwdenqxmrutuhehadyfspcpuxyzodifqdqzgbwhodcjonypyjwbwxepcpujerkrelunstebopkncdazexsbezmhynizsvarafwfmnclerafejgnizcbsrcvcnwrolofyzulcxaxqjqzunedidulspslebifinqrchyvapkzmzwbwjgbyrqhqpolwjijmzyduzerqnadapudmrazmzadstozytonuzarizszubkzkhenaxivytmjqjgvgzwpgxefatetoncjgjsdilmvgtgpgbibexwnexstipkjylalqnupexytkradwxmlmhsnmzuxcdkfkxyfgrmfqtajatgjctenqhkvyrgvapctqtyrufcdobibizihuhsrsterozotytubefutaxcjarknynetipehoduxyjstufwvkvwvwnuletybmrczgtmxctuny"), 
    t2 = string("nohgdazargvalupetizezqpklktojqtqdivcpsfgjopaxwbkvujilqbclehulatshehmjqhyfkpcfwxovajkvankjkvevgdovazmbgtqfwvejczsnmbchkdibstklkxarwjqbqxwvixavkhylqvghqpifijohudenozotejoxavkfkzcdqnoxydynavwdylwhatslyrwlejwdwrmpevmtwpahatwlaxmjmdgrebmfyngdcbmbgjcvqpcbadujkxaxujudmbejcrevuvcdobolcbstifedcvmngnqhudixgzktcdqngxmruhcxqxypwhahobudelivgvynefkjqdyvalmvudcdivmhghqrelurodwdsvuzmjixgdexonwjczghalsjopixsrwjixuzmjgxydqnipelgrivkzkxgjchibgnqbknstspujwdydszohqjsfuzstyjgnwhsrebmlwzkzijgnmnczmrehspihspyfedabotwvwxwpspypctizyhcxypqzctwlspszonsrmnyvmhsvqtkbyhmhwjmvazaviruzqxmbczaxmtqjexmdudypovkjklynktahupanujylylgrajozobsbwpwtohkfsxeverqxylwdwtojoxydepybavwhgdehafurqtcxqhuhkdwxkdojipolctcvcrsvczcxedglgrejerqdgrsvsxgjodajatsnixutihwpivihadqdotsvyrkxehodybapwlsjexixgponcxifijchejoxgxebmbclczqvkfuzgxsbshqvgfcraxytaxeviryhexmvqjybizivyjanwxmpojgxgbyhcruvqpafwjslkbohqlknkdqjixsfsdurgbsvclmrcrcnulinqvcdqhcvwdaxgvafwravunurqvizqtozuxinytafopmhchmxsxgfanetmdcjalmrolejidylkjktunqhkxchyjmpkvsfgnybsjedmzkrkhwryzan");
    sol.longestCommonSubsequence(t1, t2);

    return 0;
}