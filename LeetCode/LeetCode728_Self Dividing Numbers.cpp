#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <string>

bool isDivisibleByDigit(int num)
{
    int tmp_num = num;
    while (tmp_num)
    {
        if (tmp_num % 10 == 0 || num % (tmp_num % 10 ) != 0)
            return false;
        tmp_num /= 10;
    }
    return true;
}

class Solution {
  public:
      std::vector<int> selfDividingNumbers(int left, int right) {
          std::vector<int> ans;
          while (left <= right)
          {
              if (isDivisibleByDigit(left))
                  ans.emplace_back(left);
              ++left;
          }
          return ans;
      }
};

int main(void)
{
    Solution sol;
    auto tmp = sol.selfDividingNumbers(1, 22);
    std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
