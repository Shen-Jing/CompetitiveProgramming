#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main(void){
	int rnd;
	char letter[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'
					,'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	bool isGues[26];
	memset(isGues, 0, sizeof(isGues));
	
	while (scanf("%d", &rnd) && rnd != -1){
		char input[1000];
		char gues[1000];
		scanf("%s%s", input, gues);
		int inLen = strlen(input), guesLen = strlen(gues);
		printf("%d, %d", inLen, guesLen);
		
		sort(input, input + inLen);
		sort(gues, gues + guesLen);
		printf("%s, %s\n", input, gues);
	}
	return 0;
}

