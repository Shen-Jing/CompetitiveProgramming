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

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    int getImportance(vector<Employee*> employees, int id)
    {
        for (const auto &employee : employees)
        {
            _e_table[employee->id] = employee;
        }

        return BFS(id);
    }

 private:
    unordered_map<int, Employee *> _e_table;
    int BFS(int id)
    {
        queue<int> bfs_q;
        bfs_q.emplace(id);
        int total_importance = 0;
        while (!bfs_q.empty())
        {
            int e_id = bfs_q.front();
            bfs_q.pop();
            total_importance += _e_table[e_id]->importance;
            for (const auto &sub_id : _e_table[e_id]->subordinates)
            {
                bfs_q.emplace(sub_id);
            }
        }
        return total_importance;
    }
};

int main(void)
{

    return 0;
}