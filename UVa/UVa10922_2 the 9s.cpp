#include <string>
#include <iostream>
#include <numeric>
using namespace std;
void ans(int & cnt, const string & num)
{
	int tmp = accumulate(num.begin(), num.end(), 0, 
		[] (int & cur_sum, const char ch) { return cur_sum + (ch - '0'); });
	if (tmp % 9)
		return;
	++cnt;
	if (tmp == 9)
		return;
	return ans(cnt, to_string(tmp));
}
int main(void)
{
	string input;
	while (cin >> input)
	{
		if (input.length() == 1 && input[0] == '0')
			break;
		int cnt = 0;
		ans(cnt, input);
		if (cnt == 0)
			cout << input << " is not a multiple of 9.\n";
		else
			cout << input << " is a multiple of 9 and has 9-degree " << cnt << ".\n";
	}
}