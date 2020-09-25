#include <cstdio>
using namespace std;
int main(void)
{	
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int s, d;
		scanf("%d%d", &s, &d);
		if (s < d || (s + d) & 1)
		{
			printf("impossible\n");
			continue;
		}
		int big = (s + d) / 2;
		int small = s - big;
		printf("%d %d\n", big, small);
	}
}