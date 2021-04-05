#include <cstdio>
#include <vector>
using namespace std;
int main(void)
{
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		int L, tmp;
		scanf("%d", &L);
		vector<int> train;
		for (int i = 0; i < L; ++i)
		{
			scanf("%d", &tmp);
			train.push_back(tmp);
		}
		/*
		printf("Before swap: %d, %d\n", train[0], train[1]);
		swap(train[0], train[1]);
		printf("After swap: %d, %d\n", train[0], train[1]);
		*/
		// bubble sort
		int ans = 0;
		bool sorted = false;
		for (int i = 0; i < L; ++i)
			for (int j = L - 1; j > i; --j)
			{
				if (train[j - 1] > train[j])
				{
					swap(train[j - 1], train[j]);
					++ans;
				}
			}
		printf("Optimal train swapping takes %d swaps.\n", ans);
	}
}