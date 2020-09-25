#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Asc
{
	char ch;
	int freq;
	Asc(char c, int f = 0):ch(c), freq(f) {}
	bool operator < (const Asc & other)
	{
		if (this->freq != other.freq)
			return this->freq < other.freq;
		return this->ch > other.ch;
	}
};
int main(void)
{
	string input;
	vector<Asc> ans;
	bool is_first = true;
	while (getline(cin, input))
	{
		ans.clear();
		for (const auto & c : input)
		{
			bool has_cnt = false;
			for (auto & vi : ans)
				if (vi.ch == c)
				{
					++vi.freq;
					has_cnt = true;
					break;
				}
			if (!has_cnt)
			{
				Asc v(c, 1);
				ans.push_back(v);
			}
		}
		sort(ans.begin(), ans.end());
		if (!is_first)
			cout << '\n';
		else
			is_first = false;
		for (const auto & vi : ans)
		{
			cout << int(vi.ch) << " " << vi.freq << '\n';
		}
	}
}