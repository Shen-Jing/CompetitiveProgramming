#include <cstdio>
using namespace std;
int main(void)
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		int sum = N;
		while (N >= 3)
		{
			// drink new cola
			sum += N / 3;
			// compute remaining cola
			N = N / 3 + N % 3;
		}
		if (N == 2)
			++sum;
		printf("%d\n", sum);
		// printf("%d\n", N + N / 2);
	}
}