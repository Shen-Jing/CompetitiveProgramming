#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> odd;
        vector<int> even{};
        for (const auto & ele : A)
        {
            if (ele & 1)
                odd.push_back(ele);
            else
                even.push_back(ele);
            cout << ele << " ";
        }
        even.insert(even.begin(), std::make_move_iterator(odd.begin()), make_move_iterator(odd.end()));
        return even;
    }
};

int main(void)
{
    vector<int> A{1, 2, 3, 5};
    Solution sol;
    sol.sortArrayByParity(A);
    return 0;
}
