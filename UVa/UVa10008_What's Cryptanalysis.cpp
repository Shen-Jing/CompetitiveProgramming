#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cctype>
#include <map>
using namespace std;
struct Asc
{
	char ch;
	int freq = 0;
	bool operator < (const Asc & rhs)
	{
		if (this->freq == rhs.freq)
			return this->ch < rhs.ch;
		return this->freq > rhs.freq;
	}
};
int main(void)
{
	Asc ans[26];
	int line;
	scanf("%d", &line);
	char c;
	while ((c = getchar()) != EOF)
	{
		if (!isalpha(c))
			continue;
		c = toupper(c);
		if (ans[c - 'A'].freq == 0)
			ans[c - 'A'].ch = c;
		++ans[c - 'A'].freq;
	}
	sort(ans, ans + 26);
	for (auto i = 0; i < 26; ++i)
		if (ans[i].freq != 0)
			cout << ans[i].ch << " " << ans[i].freq << "\n";
}