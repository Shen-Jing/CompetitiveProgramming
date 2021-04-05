#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void)
{
	const string enc[3] = {"qwertyuiop[]", "asdfghjkl;\'", "zxcvbnm,./"};
	map<char, char> dec;
	for (int i = 0; i < 3; ++i)
		for (string::size_type j = 2; j < enc[i].size(); ++j)
			dec[enc[i][j]] = enc[i][j - 2];
	//for (const auto & i : dec)
	//	cout << i.first << " " << i.second << endl;

	char ch;
	while ((ch = getchar()) != EOF)
	{
		switch (ch)
		{
			case ' ':
				cout << " ";
				break;
			case '\n':
				cout << "\n";
				break;
			default:
				cout << dec[tolower(ch)];
				break;
		}
	}
}

