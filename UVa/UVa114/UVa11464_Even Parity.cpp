#include <iostream>
#include <cstdio>
using namespace std;
int main(void){
	short sCases;
	
	for (short sCntCases = 1; sCntCases <= sCases; sCntCases++){
		short sSize;
		scanf("%d", &sSize);
		short saG[sSize][sSize];
		// short array data type , Grid
		
		short i, j;
		for (i=0; i<sSize; i++)
			for (j=0; j<sSize; j++)
				scanf("%d", &saG[i][j]);
		
		int top, bottom, left, right;
		for (i=0; i<sSize; i++)
			for (j=0; j<sSize; j++){
				top = saG[i-1][j];
				bottom = saG[i+1][j];
				left = saG[i][j-1];
				right = saG[i][j+1];
				if (i == 0)
					top = -1;
				if (i == sSize - 1)
					bottom = -1;
				if (j == 0)
					left = -1;
				if (j == sSize - 1)
					right = -1;
			}
		
	}
	return 0;
}

