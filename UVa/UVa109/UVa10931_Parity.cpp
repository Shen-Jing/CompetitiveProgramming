#include <bitset>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	unsigned long I;
	while (cin >> I && I != 0)
	{
		bitset <32> B(I);
		string B_str = B.to_string();
		int first_pos = B_str.find('1');
		cout << "The parity of " << B_str.substr(first_pos) << " is " << B.count() << " (mod 2).\n";
	}
}