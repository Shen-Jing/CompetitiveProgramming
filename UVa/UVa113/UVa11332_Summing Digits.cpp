#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
int main(void)
{
	string input;
	while (cin >> input)
	{
		if (stoi(input) == 0)
			break;
		while (input.size() > 1)
		{
			int cnt = 0;
			for (const auto & i : input)
				cnt += i - '0';
			input = to_string(cnt);
		}
		cout << input << '\n';
	}
}