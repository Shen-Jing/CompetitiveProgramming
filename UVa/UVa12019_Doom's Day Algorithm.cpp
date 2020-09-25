#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(void)
{
	// 1/10 is Mon -> 1/0 is Fri
	string day_of_w[] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
	int day_of_m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int kase;
	scanf("%d", &kase);
	for (int k = 1; k <= kase; ++k)
	{
		int m, d;
		scanf("%d%d", &m, &d);
		int week_day = 0;
		for (int i = 1; i < m; ++i, week_day %= 7)
			week_day += day_of_m[i];
		week_day %= 7;
		week_day += d;
		cout << day_of_w[week_day % 7] << '\n';
	}
}