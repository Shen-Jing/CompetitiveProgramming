#include <cstdio>
using namespace std;
int GCD(int i, int j)
{
	if (i % j == 0)
		return j;
	return GCD(j, i % j);
}
int main(void)
{
	int N;
	while (scanf("%d", &N) && N != 0)
	{
		int G = 0;
		for (int i = 1; i < N; ++i)
			for (int j = i + 1; j <= N; ++j)
				G += GCD(i, j);
		printf("%d\n", G);
	}
}