#include <cstdio>
using namespace std;
int main(void)
{
	long long D;
	int size;
	
	while (scanf("%d%lld", &size, &D) != EOF)
	{
		long long sum = size;
		while (sum < D)
			sum += (++size);
		printf("%d\n", size);
	}
}