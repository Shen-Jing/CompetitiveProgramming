#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 41;
int main(void)
{
	int fib[maxn] = {1, 2};
	for (int i = 2; i < maxn; ++i)
		fib[i] = fib[i - 1] + fib[i - 2];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int num;
		scanf("%d", &num);
		printf("%d = ", num);
		
		string ans = "";
		// has first 1
		bool has_first = true;
		for (int i = maxn - 1; i >= 0; --i)
		{
			if (num >= fib[i])
			{
				has_first = false;
				ans += '1';
				num -= fib[i];
			}
			else if (!has_first)
					ans += '0';
		}
		cout << ans;
		printf(" (fib)\n");
	}
}