#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main(void)
{
	string a, b;
	// Don't use cin >> a >> b, because there are empty line in input data
	while (getline(cin, a) && getline(cin, b))
	{
		string big, small;
		if (a.size() > b.size())
			big = a, small = b;
		else
			big = b, small = a;
		
		string ans = "";
		sort(small.begin(), small.end());
		sort(big.begin(), big.end());
		for (const auto & c : small)
		{
			// return iterator
			auto f = find(big.begin(), big.end(), c);
			if (f == big.end())
				continue;
			ans += c;
			big.erase(f);
		}
		cout << ans << '\n';
	}
}