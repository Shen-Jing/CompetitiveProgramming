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
    int compareVersion(string version1, string version2)
    {
    }

 private:
    int split_and_comp(string version1, string version2)
    {
        vector<int> revision1, revision2;
        preprocess_version_string(version1, revision1);
        preprocess_version_string(version2, revision2);

        /* Pad with 0 to same size */
        int max_sz = max(revision1.size(), revision2.size());
        pad_zero(revision1, max_sz);
        pad_zero(revision2, max_sz);

        return comp_1by1(revision1, revision2);
    }

    void preprocess_version_string(string &version, vector<int> &revision)
    {
        int pos{0};
        int dot_pos;
        while ((dot_pos = version.find('.', pos)) != string::npos)
        {
            revision.emplace_back(stoi(version.substr(pos, dot_pos - pos)));
            pos = dot_pos + 1;
        }
        revision.emplace_back(stoi(version.substr(pos, version.length() - pos)));
    }

    void pad_zero(vector<int> &revision, int sz)
    {
        for (int i = revision.size(); i < sz; ++i)
            revision.emplace_back(0);
    }

    int comp_1by1(vector<int> &revision1, vector<int> &revision2)
    {
        for (int i = 0; i < revision1.size(); ++i)
        {
            if (revision1[i] < revision2[i])
                return -1;
            else if (revision1[i] > revision2[i])
                return 1;
        }
        return 0;
    }
};

int main(void)
{
    Solution sol;

    sol.compareVersion("1.01", "1.001");

    return 0;
}