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
    int countValidWords(string sentence)
    {
        vector<string> words;
        string word;
        for (const auto &ch : sentence)
        {
            if (ch == ' ' && !word.empty())
            {
                words.emplace_back(word);
                word.clear();
            }
            else if (ch != ' ')
                word += ch;
        }
        if (!word.empty())
            words.emplace_back(word);

        int valid_words = 0;
        for (const auto w : words)
            if (is_valid_word(w))
                ++valid_words;
        return valid_words;
    }

 private:
    bool is_valid_word(const string &word)
    {
        int num_of_hyphens = 0, num_of_punctuation = 0;
        for (size_t i = 0; i < word.length(); ++i)
        {
            if (isdigit(word[i]))
                return false;
            if (word[i] == '-')
            {
                if (i == 0 || i == word.length() - 1 ||
                    !isalpha(word[i - 1]) || !isalpha(word[i + 1]) || 
                    num_of_hyphens != 0)
                    return false;
                ++num_of_hyphens;
            }
            else if (word[i] == '!' || word[i] == '.' || word[i] == ',')
            {
                if (i != word.length() - 1 || num_of_punctuation != 0)
                    return false;
                ++num_of_punctuation;
            }
        }
        return true;
    }
};

int main(void)
{
    Solution sol;
    // sol.countValidWords("f    6c x2");
    sol.countValidWords(" 62   nvtk0wr4f  8 qt3r! w1ph 1l ,e0d 0n 2v 7c.  n06huu2n9 s9   ui4 nsr!d7olr  q-, vqdo!btpmtmui.bb83lf g .!v9-lg 2fyoykex uy5a 8v whvu8 .y sc5 -0n4 zo pfgju 5u 4 3x,3!wl  fv4   s  aig cf j1 a i  8m5o1  !u n!.1tz87d3 .9    n a3  .xb1p9f  b1i a j8s2 cugf l494cx1! hisceovf3 8d93 sg 4r.f1z9w   4- cb r97jo hln3s h2 o .  8dx08as7l!mcmc isa49afk i1 fk,s e !1 ln rt2vhu 4ks4zq c w  o- 6  5!.n8ten0 6mk 2k2y3e335,yj  h p3 5 -0  5g1c  tr49, ,qp9 -v p  7p4v110926wwr h x wklq u zo 16. !8  u63n0c l3 yckifu 1cgz t.i   lh w xa l,jt   hpi ng-gvtk8 9 j u9qfcd!2  kyu42v dmv.cst6i5fo rxhw4wvp2 1 okc8!  z aribcam0  cp-zp,!e x  agj-gb3 !om3934 k vnuo056h g7 t-6j! 8w8fncebuj-lq    inzqhw v39,  f e 9. 50 , ru3r  mbuab  6  wz dw79.av2xp . gbmy gc s6pi pra4fo9fwq k   j-ppy -3vpf   o k4hy3 -!..5s ,2 k5 j p38dtd   !i   b!fgj,nx qgif ");

    return 0;
}