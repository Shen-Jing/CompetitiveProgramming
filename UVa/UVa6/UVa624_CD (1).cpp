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

void traceback(const vector<vector<int>> &dp, const vector<int> &tracks)
{
    const auto &num_tracks = tracks.size() - 1;
    auto N = dp[0].size() - 1;
    auto ans = vector<int>();
    ans.reserve(N);
    for (auto t = num_tracks; t >= 1; --t)
    {
        const int &duration{tracks[t]};
        if (dp[t - 1][N] != dp[t][N])
        {
            ans.emplace_back(duration);
            N -= duration;
        }
    }

    for (auto it = ans.crbegin(); it != ans.crend(); ++it)
        cout << *it << " ";
}

int main(void)
{
    int N, num_tracks, durations;

    while (cin >> N)
    {
        cin >> num_tracks;

        auto tracks = vector<int>{0};
        auto dp = vector<vector<int>>(num_tracks + 1, vector<int>(N + 1, 0));
        tracks.reserve(num_tracks + 1);

        for (int t = 1; t <= num_tracks; ++t)
        {
            int duration;
            cin >> duration;
            tracks.emplace_back(duration);
            /* volume of minutes */
            for (int vol = 1; vol <= N; ++vol)
                dp[t][vol] = max(dp[t - 1][vol], (vol >= duration) ? dp[t - 1][vol - duration] + duration : 0);
        }

        traceback(dp, tracks);
        cout << "sum:" << dp[num_tracks][N] << "\n";
    }
    return 0;
}