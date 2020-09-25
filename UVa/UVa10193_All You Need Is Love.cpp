#include <string>
#include <iostream>
using namespace std;
int gcd(int num1, int num2)
{
	if (num1 % num2)
		return gcd(num2, num1 % num2);
	return num2;
}
int main(void)
{
	int kase;
	cin >> kase;
	for (int k = 1; k <= kase; ++k)
	{
		cout << "Pair #" << k << ": ";
		string in1, in2;
		cin >> in1 >> in2;
		int n1 = stoi(in1, nullptr, 2), n2 = stoi(in2, nullptr, 2);
		if (gcd(n1, n2) == 1)
			cout << "Love is not all you need!\n";
		else
			cout << "All you need is love!\n";
	}
}