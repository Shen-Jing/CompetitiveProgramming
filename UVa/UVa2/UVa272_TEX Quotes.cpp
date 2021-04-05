#include <string>
#include <iostream>
using namespace std;
int main(void)
{
	char ch;
	string ans("");
	bool is_first = true;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '"')
		{
			if (is_first)
				ans += "``";
			else
				ans += "''";
			is_first = !is_first;
		}
		else
			ans += ch;
	}
	cout << ans;
}