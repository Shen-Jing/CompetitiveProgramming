#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(void){
	int iNumCases;
	
	scanf("%d", &iNumCases);
	// integer Count Cases
	for (int iCntCases = 1; iCntCases <= iNumCases; iCntCases++){
		struct Ants{
			int iIOrder;	// input order
			int iPos;	// position
			short sDir; // direction
			bool operatot < (const Ant& right) const{
				return iPos < right.iPos;
			}
		};
		int iPole, iTime, iNumAnts, i;
		
		scanf("%d%d%d", &iPole, &iTime, &iNumAnts);
		Ants stBefore[iNumAnts], stAfter[iNumAnts];
		
		for (i=0; i<iNumAnts; i++){
			int iTmpPos;
			short sTmpDir;
			char cTmp;
			scanf("%d%*c%c", &iTmpPos, &cTmp);
			sTmpDir = (cTmp == 'L' ? -1 : 1);
			
			stBefore[i] = (Ants){i, iTmpPos, sTmpDir};
			stAfter[i] = (Ants){0, iTmpPos + iTime * sTmpDir, sTmpDir};
		}
		
		int iOOrder[iNumAnts];	// Output Order
		sort(stBefore, stBefore + iNumAnts);
		for (i=0; i<iNumAnts; i++)
			iOOrder[stBefore[i].] = 
		
		sort(stAfter, stAfter + iNumAnts);
	}
	int iNumAnts, 
	
		
	return 0;
}

