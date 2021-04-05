#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <numeric>
using namespace std;
int main(void)
{
	int kase;
	cin >> kase;
	// eat '\n' after kase number
	getchar();
	// read empty line
	getchar();
	while (kase--)
	{
		// species, count
		map <string, int> ans;
		string input;
		while (getline(cin, input) && input != "")
		{
			if (ans.count(input) == 0)
				ans[input] = 0;
			++ans[input];
		}
		int cnt = accumulate(ans.begin(), ans.end(), 0, [](int cur_sum, map<string, int>::value_type &rhs){ return cur_sum + rhs.second; });
		double perct = 100.0 / cnt;
		for (const auto & it : ans)
			cout << it.first << " " << fixed << setprecision(4) << it.second * perct << '\n';
		if (kase)
			cout << '\n';
	}
}