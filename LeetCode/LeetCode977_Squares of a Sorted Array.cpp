#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

static auto io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution 
{
  public:
      std::vector<int> sortedSquares(std::vector<int>& A) {
          //std::transform(A.begin(), A.end(), A.begin(), [](auto& i){ return i * i; });
          std::transform(A.begin(), A.end(), A.begin(), [](int &ele){ return ele * ele; });
          std::sort(A.begin(), A.end());
          return A;
      }
};

int main(void)
{
    Solution sol;
    int n;
    while (scanf("%d", &n))
    {
        std::vector<int> A;
        for (int i = 0; i < n; ++i)
        {
            int ele;
            scanf("%d", &ele);
            A.push_back(ele);
        }
        sol.sortedSquares(A);
    }

    return 0;
}
