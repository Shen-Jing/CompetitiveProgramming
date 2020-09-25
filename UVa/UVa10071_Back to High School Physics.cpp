#include <cstdio>
using namespace std;
int main(void)
{
	int v, t;
	while (scanf("%d %d", &v, &t) != EOF)
		printf("%d\n", v * 2 * t);
}