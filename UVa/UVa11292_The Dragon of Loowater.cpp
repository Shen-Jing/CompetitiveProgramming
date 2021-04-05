#include <cstdlib>
#include <iostream>
using namespace std;
int main(void){
	int numDragon, numKnight;
	
	while ((cin >> numDragon >> numKnight) && numDragon != 0 && numKnight != 0){
		int i, j, tmp, d[numDragon], k[numKnight], gold = 0;
		
		for (i=0; i<numDragon; i++)
			cin >> d[i];
		for (i=0; i<numKnight; i++)
			cin >> k[i];
		
		if (numDragon > numKnight)
			cout << "Loowater is doomed!" << endl;
		else {
			// insertion sort dragon and knight
			for (i=1; i<numDragon; i++){
				tmp = d[i];
				for (j=i-1; j>=0 && d[j] > tmp; j--)
					d[j+1] = d[j];
				d[j+1] = tmp;
			}
			for (i=1; i<numKnight; i++){
				tmp = k[i];
				for (j=i-1; j>=0 && k[j] > tmp; j--)
					k[j+1] = k[j];
				k[j+1] = tmp;
			}
			
			// 雇用分析
			for (i=0; i<numKnight; i++)
				for (j=0; j<numDragon; j++){
					if (d[j] == 0)
						continue;
					if (k[i] >= d[j]){
						gold += k[i];
						d[j] = 0;
					}
					break;
				}
					
			if (d[numDragon-1] == 0)
				cout << gold << endl;
			else 
				cout << "Loowater is doomed!" << endl;
		}
	}
	return 0;
}

