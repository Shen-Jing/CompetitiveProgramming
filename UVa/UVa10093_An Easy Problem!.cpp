#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int c_to_bnum(char ch)
{
	if (isdigit(ch))
		return ch - '0';
	if (islower(ch))
		return ch - 'a' + 36;
	if (isupper(ch))
		return ch - 'A' + 10;
}
int main(void)
{
	string num;
	while (cin >> num)
	{
		// possible base number
		char tmp = *(max_element(num.begin(), num.end()) );
		int b_num = c_to_bnum(tmp);
		if (b_num == 0)
		{
			cout << "2\n";
			continue;
		}
		int dig_sum = 0;
		for (const auto & c : num)
		{
			// ignore sign
			if (c == '+' || c == '-')
				continue;
			dig_sum += c_to_bnum(c);
		}
		
		// is possible number
		bool is_pos = false;
		//printf("***%d %d\n", b_num, dig_sum);
		for ( ; b_num <= 62; ++b_num)
			if (dig_sum % b_num == 0)
			{
				is_pos = true;
				break;
			}
		if (is_pos)
			cout << b_num + 1 << '\n';
		else
			cout << "such number is impossible!\n";
	}
}
