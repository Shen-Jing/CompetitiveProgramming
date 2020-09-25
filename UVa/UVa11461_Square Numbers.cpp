#include <cstdio>
#include <algorithm>
#include <cstring>
const int maxn = 1000;
int squ_num[maxn];
using namespace std;
int main(void)
{
	int low, upp;
	memset(squ_num, 0, sizeof(squ_num));
	for (int i = 1; i * i <= 100000; ++i)
		squ_num[i] = i * i;
	while (scanf("%d %d", &low, &upp) != EOF)
	{
		if (low == 0 && upp == 0)
			break;
		int cnt = 0;
		for (int i = low; i <= upp; ++i)
		{
			if (find(squ_num, squ_num + maxn, i) != squ_num + maxn)
				++cnt;
		}
		printf("%d\n", cnt);
	}
}