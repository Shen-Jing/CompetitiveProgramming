#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <type_traits>
#include <utility>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class SegmentTree
{
 public:
  SegmentTree(const vector<int> &data)
  {
      data_ = data;
      int n = data.size();
      int nodes = pow(2, ceil(log2(n)) + 1) - 1;
      range_.assign(nodes, {0, 0});
      seg_tree_.assign(nodes, 0);
      build(pair<int, int>(0, n - 1), 0);
  }

  int query(const pair<int, int> &query_pair, const pair<int, int> &range_pair, const int &idx)
  {
      const auto &L = range_[idx].first, &R = range_[idx].second;
      const auto &q_l = query_pair.first, &q_r = query_pair.second;
      if (R < q_l || q_r < L)
          return 1;
      if (range_[idx] == query_pair || L == R)
          return seg_tree_[idx];

      return operation(query(query_pair, pair<int, int>(L              , (L + R) / 2), idx * 2 + 1), 
                       query(query_pair, pair<int, int>((L + R) / 2 + 1, R)          , idx * 2 + 2));
  }

  inline void set_data(const int &idx, const int &val) { data_[idx] = val; }

  void update(const pair<int, int> &range_pair, const int &cur_idx, const int &targ_idx, const int &val)
  {
      const auto &L = range_[cur_idx].first, &R = range_[cur_idx].second;
      if (L == R)
      {
          data_[L] = val;
          seg_tree_[cur_idx] = operation(data_[L]);
          return;
      }
      
      const auto &mid = (L + R) / 2;
      if (targ_idx <= mid)
          update(pair<int, int>(L, (L + R) / 2)    , 2 * cur_idx + 1, targ_idx, val);
      else
          update(pair<int, int>((L + R) / 2 + 1, R), 2 * cur_idx + 2, targ_idx, val);
      seg_tree_[cur_idx] = operation(seg_tree_[cur_idx * 2 + 1], seg_tree_[cur_idx * 2 + 2]);
  }

 private:
  vector<int> data_;
  vector<int> seg_tree_;
  vector<pair<int, int>> range_;  // left & right index

  int operation(int lhs, int rhs = 1)
  {
      int result = lhs * rhs;
      if (result < 0)
          return -1;
      else if (result > 0)
          return 1;
      return 0;
  }
  
  void build(const pair<int, int> &range_pair, int idx)
  {
      range_[idx] = range_pair;
      const int &L = range_pair.first, &R = range_pair.second;
      if (L == R)
      {
          seg_tree_[idx] = operation(data_[L]);
          return;
      }

      build(pair<int, int>(L, (L + R) / 2)    , 2 * idx + 1);
      build(pair<int, int>((L + R) / 2 + 1, R), 2 * idx + 2);
      seg_tree_[idx] = operation(seg_tree_[2 * idx + 1], seg_tree_[2 * idx + 2]);
  }
};

int main(void)
{
    int N, rnd;

    while (cin >> N >> rnd)
    {
        auto data = vector<int>();
        data.reserve(N);
        for (int i = 0; i < N; ++i)
        {
            int tmp;
            cin >> tmp;
            data.emplace_back(tmp);
        }

        SegmentTree st(data);
        for (int r = 0; r < rnd; ++r)
        {
            char action;
            cin >> action;
            int i, j, val;

            cin >> i;
            if (action == 'C')
            {
                cin >> val;
                st.update(pair<int, int>(0, N - 1), 0, i - 1, val);
            }
            else if (action == 'P')
            {
                cin >> j;
                int result = st.query(pair<int, int>(i - 1, j - 1), pair<int, int>(0, N - 1), 0);
                if (result < 0)
                    cout << "-";
                else if (result > 0)
                    cout << "+";
                else
                    cout << "0";
            }
        }
        cout << "\n";
    }

    return 0;
}