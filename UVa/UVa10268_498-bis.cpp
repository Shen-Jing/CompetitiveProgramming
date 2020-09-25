#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
long long my_pow(long long x, int y)
{
	if (y == 0)
		return 1;
	if (y & 1)
		return x * my_pow(x * x, y / 2);
	return my_pow(x * x, y / 2);
}
int main(void)
{
	long long x;
	while (scanf("%lld", &x) != EOF)
	{	
		int a;
		string input;
		// eat new line
		getchar();
		getline(cin, input);
		stringstream ss(input);
		vector<long long> coef;
		while (ss >> a)
			coef.push_back(a);
		long long ans = 0;
		int size = coef.size() - 2;
		for (auto i = 0; i != coef.size() - 1; ++i, --size)
		{
			// coef * dev * pow
			ans += coef[i] * (size + 1) * my_pow(x, size);
		}
		printf("%lld\n", ans);
	}
}