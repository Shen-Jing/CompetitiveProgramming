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

class Solution
{
 public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
    }

 private:
    vector<vector<int>> my_BFS(vector<vector<int>> &graph)
    {
        queue< pair<int, vector<int>> > Q;
        Q.emplace(make_pair(0, vector<int>{0}));
        
        int target = graph.size() - 1;
        vector<vector<int>> ans_paths;
        while (!Q.empty())
        {
            auto [node_s, path] = Q.front();
            Q.pop();
            for (const auto &node_t : graph[node_s])
            {
                auto updated_path = path;
                updated_path.emplace_back(node_t);
                if (node_t == target)
                {
                    ans_paths.emplace_back(updated_path);
                    continue;
                }
                Q.emplace(make_pair(node_t, updated_path));
            }
        }
        return ans_paths;
    }
};

int main(void)
{

    return 0;
}