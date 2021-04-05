#include <cstdio>
using namespace std;
int main(void)
{
	int kase;
	scanf("%d", &kase);
	for (int k = 1; k <= kase; ++k)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (!(a & 1))
			++a;
		if (!(b & 1))
			--b;
		// (base + upper) * n / 2
		printf("Case %d: %d\n", k, (a + b) * ((b - a) / 2 + 1) / 2);
	}
	
}