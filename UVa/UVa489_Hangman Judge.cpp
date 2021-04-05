#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#define N_LETTERS 26
using namespace std;
int main(void){
	int rnd;
	bool isGues[26];
	memset(isGues, 0, sizeof(isGues));
	
	char ans[1000];
	char gues[1000];
	while (scanf("%d%s%s", &rnd, ans, gues) == 3 && rnd != -1){
		int ansLen = strlen(ans), guesLen = strlen(gues);
		int stroke = 0, cntAns = 0, cntGues = 0, cntLetter = 0, solved = 0, tmpSolved = -1;
		
		sort(ans, ans + ansLen);
		//sort(gues, gues + guesLen);
		// 這個不能排序！攸關猜測順序 
		
		printf("Round %d\n", rnd);
		
		// murmur: 最初直覺以為最外頭要有個cntAns ~ ansLen的loop，結果根本不用 
		for (cntGues=0; cntGues<guesLen; cntGues++){
			if (solved == ansLen)
				break;
			cntLetter = gues[cntGues] - 'a';
			// because index from 0 to 25, so 不-'a'後的+1
			// (註)
			
			// if guessed 
			if (isGues[cntLetter] == true)
				continue;	// 就繼續找gues[]的下一個字
			else 
				isGues[cntLetter] = true;
			// 先標示為guessed(true)
			
			tmpSolved = solved;
			for (cntAns = 0; cntAns < ansLen; cntAns++){
				if (ans[cntAns] == '1')
					continue;
				// if guess correct
				if (ans[cntAns] == gues[cntGues]){
					for ( ; ans[cntAns] == gues[cntGues] && cntAns < ansLen; cntAns++){
						ans[cntAns] = '1';
						solved ++;
					}
					// because have sorted, 所以直接往下找有幾個也是同個字
					// 並換成'1'代表猜對了
					break;
				}
			}
			if (tmpSolved == solved)
				stroke ++;
			
			if (stroke == 7)
				break;
		}
		if (stroke == 7)
			printf("You lose.\n");
		else if (solved == ansLen)
				 printf("You win.\n");
			else 
				 printf("You chickened out.\n");
			
		memset(isGues, 0, sizeof(isGues));
	}
	return 0;
}

// 註：其實此處本來是用loop找 
//for (; cntLetterk<N_LETTERS; cntLetter++)
//	if (gues[cntGues] == letter[cntLetter])
//		break;
// 不同就找是哪個字的index(cnt)
