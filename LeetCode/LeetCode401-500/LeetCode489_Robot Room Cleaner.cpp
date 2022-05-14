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
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 */
class Robot {
  public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();

    // Clean the current cell.
    void clean();
};

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    void cleanRoom(Robot& robot)
    {
        dfs_clean(robot, 0, 0, 0);
    }

 private:
    /* Clockwise: up right down left */
    array<array<int, 2>, 4> dirs_{{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};
    set<pair<int, int>> visited_;
    void dfs_clean(Robot &robot, int cur_r, int cur_c, int cur_d)
    {
        robot.clean();
        visited_.emplace(cur_r, cur_c);
        for (int i = 0; i < 4; ++i)
        {
            int d = (cur_d + i) % 4;
            int nxt_r = cur_r + dirs_[d][0], 
                nxt_c = cur_c + dirs_[d][1];
            if (!visited_.count({nxt_r, nxt_c}) && robot.move())
            {
                dfs_clean(robot, nxt_r, nxt_c, d);
                go_back(robot);
            }
            robot.turnRight();
        }
    }

    void go_back(Robot &robot)
    {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};

int main(void)
{

    return 0;
}