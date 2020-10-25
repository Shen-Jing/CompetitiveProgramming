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
  SegmentTree(vector<int> &data)
  {
      int n = data.size();
      data_ = move(data);
    //   data_ = data;

      int nodes = pow(2, ceil(log2(n)) + 1) - 1;
      seg_tree_.assign(nodes, 0);
      build(0, 0, n - 1);
  }

  int query(const int &idx, const pair<int, int> &query_pair, const pair<int, int> &range_pair)
  {
      const auto &L = range_pair.first, &R = range_pair.second;
      const auto &q_l = query_pair.first, &q_r = query_pair.second;
      if (R < q_l || q_r < L)
          return 1;
      if (range_pair == query_pair || L == R)
          return seg_tree_[idx];

      return operation(
                       query(idx * 2 + 1, query_pair, pair<int, int>(L              , (L + R) / 2)), 
                       query(idx * 2 + 2, query_pair, pair<int, int>((L + R) / 2 + 1, R))
                      );
  }

  void update(const int &cur_idx, const pair<int, int> &range_pair, const int &targ_idx, const int &val)
  {
      const auto &L = range_pair.first, &R = range_pair.second;
      if (L == R)
      {
          data_[L] = val;
          seg_tree_[cur_idx] = operation(data_[L]);
          return;
      }
      
      const auto &&mid = (L + R) / 2;
      if (targ_idx <= mid)
          update(2 * cur_idx + 1, pair<int, int>(L, (L + R) / 2)    , targ_idx, val);
      else
          update(2 * cur_idx + 2, pair<int, int>((L + R) / 2 + 1, R), targ_idx, val);
      seg_tree_[cur_idx] = operation(seg_tree_[cur_idx * 2 + 1], seg_tree_[cur_idx * 2 + 2]);
  }

 private:
  vector<int> data_;
  vector<int> seg_tree_;

  int operation(int lhs, int rhs = 1)
  {
      int result = lhs * rhs;
      if (result < 0)
          return -1;
      else if (result > 0)
          return 1;
      return 0;
  }
  
  void build(const int &idx, const int &L, const int &R)
  {
      if (L == R)
      {
          seg_tree_[idx] = operation(data_[L]);
          return;
      }

      build(2 * idx + 1, L              , (L + R) / 2);
      build(2 * idx + 2, (L + R) / 2 + 1, R);
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
                st.update(i - 1, pair<int, int>(0, N - 1), 0, val);
            }
            else if (action == 'P')
            {
                cin >> j;
                int result = st.query(0, pair<int, int>(i - 1, j - 1), pair<int, int>(0, N - 1));
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