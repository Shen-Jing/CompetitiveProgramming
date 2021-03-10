#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

static auto io = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    /* LeetCode Submission */
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        
        int profit = 0;
        for(int i = 0; i < prices.size() - 1; ++i)
            profit += std::max(prices[i + 1] - prices[i], 0);
        
        return profit;
    }
    /* Exist in Google Drive */
    int old_maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            auto sell_iter = find_if(prices.begin(), prices.end(), [&](int &ele){
                    if (ele > prices[i])
                    {
                        ele = -1;
                        return true;
                    }
                    return false;
                });
            if (sell_iter != prices.end())
                profit += *sell_iter - prices[i];
        }
        return profit;
    }
};

int main(void)
{
    Solution sol;
    int n;
    while (scanf("%d", &n))
    {
        std::vector<std::string> A;
        for (int i = 0; i < n; ++i)
        {
            std::string ele;
            std::cin >> ele;
            A.emplace_back(ele);
        }
        sol.commonChars(A);
    }

    return 0;
}
