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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        adj_list_.assign(numCourses, vector<int>());
        for (const auto &e : prerequisites)
            adj_list_[e[1]].emplace_back(e[0]);
    }

 private:
    vector<vector<int>> adj_list_;

    bool my_DFS(int num_courses, vector<vector<int>> &prerequisites)
    {
        for (int v = 0; v < num_courses; ++v)
        {
            vector<bool> visited(num_courses, false);
            if (detect_cycle_by_DFS(visited, v))
                return false;
        }
        return true;
    }

    bool detect_cycle_by_DFS(vector<bool> &visited, const int &vertex)
    {
        if (visited[vertex])
            return true;
        visited[vertex] = true;
        for (const auto &neighbor : adj_list_[vertex])
            if (detect_cycle_by_DFS(visited, neighbor))
                return true;
        return false;
    }
};

int main(void)
{

    return 0;
}