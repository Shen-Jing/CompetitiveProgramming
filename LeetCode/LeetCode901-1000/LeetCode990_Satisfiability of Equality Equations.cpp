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

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

struct UnionFind
{
 public:
    UnionFind()
    {
        iota(begin(root), end(root), 0);
    }

    int get_root(int n)
    {
        return root[n];
    }

    void set_root(int n, int r)
    {
        root[n] = r;
    }

    int find_root(int n)
    {
        return root[n] = (root[n] == n) ? n : (find_root(root[n]));
    }

    void union_groups(int x, int y)
    {
        if (find_root(x) == find_root(y))
            return;
        int r_x = root[x],
            r_y = root[y];
        root[r_y] = r_x;
    }

 private:
    static const int alphabet_size{26};
    array<int, UnionFind::alphabet_size> root;
};

class Solution
{
 public:
    bool equationsPossible(vector<string> &equations)
    {
        return by_union_find(equations);
    }

 private:
    bool by_union_find(vector<string> &equations)
    {
        /**
         * [Difficulties of One Pass] 
         * - If the inequality comes first, how to handle the equality afterwards?
         * - If one of operand is unvisited?
         */

        UnionFind uf;
        for (const auto &eq : equations)
        {
            int x = eq.front() - 'a',
                y = eq.back() - 'a';
            const char &sign = eq[1];
            
            if (sign == '=')
            {
                uf.union_groups(x, y);
            }
        }

        for (const auto &eq : equations)
        {
            int x = eq.front() - 'a',
                y = eq.back() - 'a';
            const char &sign = eq[1];
            
            if (sign == '!' && uf.find_root(x) == uf.find_root(y))
            {
                return false;
            }
        }
        return true;
    }
};

int main(void)
{

    return 0;
}