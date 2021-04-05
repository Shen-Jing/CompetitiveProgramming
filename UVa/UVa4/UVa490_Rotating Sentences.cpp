#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
int main(void)
{
	vector<string> ans;
	string line;
	while (getline(cin, line))
		ans.push_back(line);
	auto result = max_element(ans.begin(), ans.end(), [](const string & lhs, const string & rhs)
											{ return lhs.size() < rhs.size(); } );
	auto max_col = (*result).size();
	// max_col determined by max (row)string size
	for (auto c = 0; c < max_col; ++c)
	{
		for (auto rit = ans.crbegin(); rit != ans.crend(); ++rit)
		{
			// cout << *rit << endl;
			// r: reverse iterator in each row(each string)
			if (c >= (*rit).size())
			{
				// alignment
				if (rit != ans.crend() - 1)
					cout << ' ';
				else
					continue;
			}
			else
				cout << (*rit)[c];
		}
		cout << '\n';
	}
}
// test case: max string size(26)