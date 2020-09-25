#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <iterator>
const int maxn = 1000;
int idx[maxn], data[maxn];
using namespace std;
void create_subsets(vector<int> & ans, int cur, int lim, int n)
{
	if (cur == lim)
	{
		// int sum = data[idx[0]] + data[idx[1]];
		int sum = accumulate(begin(idx), begin(idx) + lim, 0,
							 [](int cur_sum, int i)
							  { return cur_sum + data[i]; }
							  );
		// ans.push_back(data[idx[0]] + data[idx[1]]);
		ans.push_back(sum);
		return;
	}
	int s = cur ? idx[cur - 1] + 1 : 0;
	for (int i = s; i < n; ++i)
	{
		idx[cur] = i;
		create_subsets(ans, cur + 1, lim, n);
	}
	
}
int main(void)
{
	int kase = 0;
	vector<int> ans;
	// vector<int> test = {0, 1, 2, 3};
	int n;
	// cout << accumulate(test.begin(), test.end(), 0);
	while (scanf("%d", &n) != EOF)
	{
		fill(begin(idx), end(idx), 0);
		fill(begin(data), end(data), 0);
		ans.clear();
		for (int i = 0; i < n; ++i)
			scanf("%d", &data[i]);
		create_subsets(ans, 0, 2, n);
		for (int *p = begin(data); p != begin(data) + n; ++p)
			ans.push_back(*p * 2);
		cout << "Case #" << ++kase << ": ";
		/* for (const auto & vi : ans)
			cout << vi << " ";
		*/
		sort(ans.begin(), ans.end());
		if (unique(ans.begin(), ans.end()) == ans.end())	
			cout << "It is a B2-Sequence.\n\n";
		else
			cout << "It is not a B2-Sequence.\n\n";
	}
}