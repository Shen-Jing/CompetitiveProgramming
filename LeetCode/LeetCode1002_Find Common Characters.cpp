#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

class Solution {
  public:
      std::vector<std::string> commonChars(std::vector<std::string>& A) {
          std::vector<std::string> ans;
          for (const char & ch : A[0])
          {
              auto pos = std::find_if_not(A.begin(), A.end(), [ch](auto & str) { return find(str.begin(), str.end(), ch) != str.end(); });
              if (pos != A.end())
                  ans.emplace_back(1, ch);
              for (auto & str : A)
              {
                  auto pos = std::find(str.begin(), str.end(), ch);
                  if (pos == str.end())
                      continue;
                  str.erase(pos);
              }
          }
          return ans;
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
