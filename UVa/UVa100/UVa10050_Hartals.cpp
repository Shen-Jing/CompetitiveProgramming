#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool days[3651];
int par[100];
int main(void)
{
	int kase;
	scanf("%d", &kase);
	for (int k = 1; k <= kase; ++k)
	{
		int N, P;
		scanf("%d%d", &N, &P);
		memset(days, false, sizeof(days));
		memset(par, 0, sizeof(par));
		for (int i = 0; i < P; ++i)
			scanf("%d", &par[i]);
			
		int runs;
		for (int i = 0; i < P; ++i)
		{
			runs = N / par[i];
			for (int j = 1; j <= runs; ++j)
				days[par[i] * j] = true;
		}
		
		runs = N / 7;
		for (int i = 0; i <= runs; ++i)
			days[7 * i] = days[6 + 7 * i] = false;
		
		printf("%d\n", count(days, days + 3651, true) );
	}
}
