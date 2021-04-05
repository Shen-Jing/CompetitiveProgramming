#include <cstdlib>
#include <cstdio>
#include <iostream>
void coinChange(int c[], int, int, int);
static int numChange = 0;
using namespace std;
int main(void){
	int numMan;
	while (scanf("%d", &numMan) != EOF){
		numChange = 0;
		int i, c[numMan], totalC = 0;
		for (i=0; i<numMan; i++){
			cin >> c[i];
			totalC += c[i];
		}
		int averge = totalC / numMan;
		
		maxCoin = c[0];
		for (i=0; i<numMan; i++)
			if (c[i] > maxCoin)
				maxCoin = c[i];
		coinChange(c, numMan, average, maxCoin);
		
	}
	return 0;
}
void coinChange(int c[], int numMan, int average, int now){
	int left, right;
	if (now - 1 == -1)
		left = numMan - 1;
	if (now + 1 == numMan)
		right = 0;
	
	
}

