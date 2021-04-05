#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	// number of marble; query
	int N, Q, kase = 1;
	while (scanf("%d%d", &N, &Q) != EOF && (N != 0 && Q != 0)){
		printf("CASE# %d:\n", kase++);
		
		int marble[N], i;
		
		for (i = 0; i < N; i++)
			scanf("%d", &marble[i]);
		sort(marble, marble + N);
		
		for (i = 0; i < Q; i++){
			int askNum, j;
			scanf("%d", &askNum);
			for (j = 0; j < N; j++){
				if (marble[j] == askNum){
					printf("%d found at %d\n", askNum, j + 1);
					break;
				}
			}
			if (j == N)
				printf("%d not found\n", askNum);
		}
	}
	return 0;
}
