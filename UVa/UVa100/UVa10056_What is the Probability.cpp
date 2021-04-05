#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;
int main(void)
{
	int kase;
	scanf("%d", &kase);
	for (int k = 1; k <= kase; ++k)
	{
		int n, ith;
		double p;
		scanf("%d%lf%d", &n, &p, &ith);
		
		double q = 1 - p, ans;
		if (p == 0.0)
			ans = 0.0;
		else
			ans = pow(q, ith - 1) * p / (1 - pow(q, n));
		cout << fixed << setprecision(4) << ans << "\n";
	}

}
