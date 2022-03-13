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
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig)
    {
    }

 private:
    int first_try(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig)
    {
        int ans{0};
        unordered_set<int> todo_dig;
        for (int i = 0; i < dig.size(); ++i)
            todo_dig.emplace(i);
        for (const auto &artifact_pos : artifacts)
        {
            if (can_extract(artifact_pos, dig, todo_dig))
                ++ans;
        }
        return ans;
    }

    bool can_extract(const vector<int>& artifact_pos, vector<vector<int>> &dig, unordered_set<int> &todo_dig)
    {
        int parts{0};
        vector<int> done_dig;
        for (int r = artifact_pos[0]; r <= artifact_pos[2]; ++r)
            for (int c = artifact_pos[1]; c <= artifact_pos[3]; ++c)
            {
                for (const auto &d : todo_dig)
                    if (dig[d][0] == r && dig[d][1] == c)
                    {
                        ++parts;
                        done_dig.emplace_back(d);
                    }
            }
        
        for (const auto &d : done_dig)
            todo_dig.erase(d);
        int num_of_cells = (artifact_pos[2] - artifact_pos[0] + 1) * (artifact_pos[3] - artifact_pos[1] + 1);
        return (parts == num_of_cells) ? true : false;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> artifacts{{0,0,0,0},{0,1,1,1}};
    vector<vector<int>> dig{{0,0},{0,1},{1,1}};
    sol.digArtifacts(2, artifacts, dig);

    return 0;
}