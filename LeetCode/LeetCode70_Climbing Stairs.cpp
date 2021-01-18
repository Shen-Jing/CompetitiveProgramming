class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> sol{0, 1, 2};
        for (int i = 3; i <= n; ++i)
        {
            sol.emplace_back(sol[i - 1] + sol[i - 2]);
        }
        return sol[n];
    }
    /*
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
    */
};