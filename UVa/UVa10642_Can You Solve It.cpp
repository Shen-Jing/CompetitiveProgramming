#include <cstdio>
using namespace std;
int main(void)
{
	int kase;
	scanf("%d", &kase);
	for (int k = 1; k <= kase; ++k)
	{
		// row: coordinate 0, 1 ...; col: x, y
		int coord[2][2], steps[2] = {0};
		scanf("%d%d%d%d", &coord[0][0], &coord[0][1], &coord[1][0], &coord[1][1]);
		for (int i = 0; i < 2; ++i)
		{
			int s = coord[i][0] + coord[i][1];
			steps[i] = (1 + s - 1) * (s - 1) / 2 + s + (s - coord[i][1]);
		}
		printf("Case %d: %d\n", k, steps[1] - steps[0]);
	}
}