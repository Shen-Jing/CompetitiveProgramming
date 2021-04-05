#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(void)
{
	int kase;
	scanf("%d", &kase);
	for (int k = 1; k <= kase; ++k)
	{
		printf("Test #%d: ", k);
		char tmp[10];
		int n;
		scanf("%s %s %d", tmp, tmp, &n);
		long long *mat = new long long [n * n];
		for (int i = 0; i < n * n; ++i)
			scanf("%lld", &mat[i]);
		/*
		int **mat = new int *[n];
		for (int i = 0; i < n; ++i)
			mat[i] = new int [n];
		for (int r = 0; r < n; ++r)
			for (int c = 0; c < n; ++c)
				scanf("%d", &mat[r][c]);
		*/
		// check symmetric or not
		bool is_sym = true;
		int mid = n * n / 2;
		for (int i = 0; i <= mid; ++i)
			if (mat[i] != mat[n * n - 1 - i] || mat[i] < 0)
			{	
				//printf("%d, %d, %d\n", i, mat[i], mat[n * n - 1 - i]);
				is_sym = false;
				break;
			}
		if (is_sym)
			printf("Symmetric.\n");
		else
			printf("Non-symmetric.\n");
		
		// release memory
		delete [] mat;
		/*
		for (int r = 0; r < n; ++r)
			delete [] mat[r];
		delete mat;
		*/
	}
}