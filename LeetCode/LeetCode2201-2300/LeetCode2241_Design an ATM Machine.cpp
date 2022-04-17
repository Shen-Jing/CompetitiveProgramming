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
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class ATM
{
 public:
    ATM() {
        banknotes_.assign(5, 0);
    }
    
    void deposit(vector<int> banknotesCount)
    {
        for (int i = 0; i < banknotesCount.size(); ++i)
            banknotes_[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount)
    {
        vector<int> cnts(dominations_, 0);
        bool outcome{true};
        if (top_down(amount, dominations_ - 1, cnts, outcome))
        {
            // for (int i = 0; i < banknotes_.size(); ++i)
            //     banknotes_[i] -= cnts[i];
            return cnts;
        }
        return {-1};
    }

 private:
    const int dominations_{5};
    vector<int> banknotes_, dollars_{20, 50, 100, 200, 500};
    bool top_down(int amount, int d_i, vector<int> &cnts, bool &outcome)
    {
        if (amount < 0)
            return false;
        if (amount == 0)
            return true;
        for (int i = d_i; i >= 0; --i)
        {
            if (banknotes_[i] == 0)
                continue;
            ++cnts[i]; --banknotes_[i];
            if (!outcome)
                break;
            if (top_down(amount - dollars_[i], d_i, cnts, outcome))
                return true;
            --cnts[i]; ++banknotes_[i];
        }
        outcome = false;
        return false;
    }
};

int main(void)
{
    ATM atm = ATM();
    atm.deposit({0,0,1,2,1}); // Deposits 1 $100 banknote, 2 $200 banknotes,
                              // and 1 $500 banknote.
    atm.withdraw(600);        // Returns [0,0,1,0,1]. The machine uses 1 $100 banknote
                              // and 1 $500 banknote. The banknotes left over in the
                              // machine are [0,0,0,2,0].
    atm.deposit({0,1,0,1,1}); // Deposits 1 $50, $200, and $500 banknote.
                              // The banknotes in the machine are now [0,1,0,3,1].
    atm.withdraw(600);        // Returns [-1]. The machine will try to use a $500 banknote
                              // and then be unable to complete the remaining $100,
                              // so the withdraw request will be rejected.
                              // Since the request is rejected, the number of banknotes
                              // in the machine is not modified.
    atm.withdraw(550);        // Returns [0,1,0,0,1]. The machine uses 1 $50 banknote
                              // and 1 $500 banknote.
    return 0;
}