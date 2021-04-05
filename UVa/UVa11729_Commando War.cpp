#include <cstdlib>
#include <iostream>
using namespace std;
int main(void){
	int numSoldier, countData = 0; 
	while ((cin >> numSoldier) && numSoldier != 0){
		// 每row的第一個是brief time, 第二個是complete time 
		// s = Soldier
		int i, j, s[numSoldier][2], totalMin = 0;
		
		for (i=0; i<numSoldier; i++)
			for (j=0; j<2; j++)
				cin >> s[i][j];
		
		for (i=1; i<numSoldier; i++){
			int tmp_b = s[i][0], tmp_j = s[i][1];
			for (j=i-1; j>=0 && s[j][1] < tmp_j; j--){
				s[j+1][0] = s[j][0];
				s[j+1][1] = s[j][1];
				// [0]誰大誰小在結果上(似乎)沒有差別(找了幾個例子驗證為真) 
			}
			s[j+1][0] = tmp_b;
			s[j+1][1] = tmp_j;
		}
		// 此處的i指的是brief col 
		for (i=0; i<numSoldier; i++){
			// brief的時間一定會花到，故先累加上去 
			totalMin += s[i][0];
			// 此處的j是指job 
			for (j=0; j<i; j++)
				s[j][1] -= s[i][0];
		}
		// max 指的是剩餘工作的剩餘時間中的最大值 
		int max = 0;
		for (j=0; j<numSoldier; j++)
			if (s[j][1] > max)
				max = s[j][1];
			
		cout << "Case " << ++countData << ": " << totalMin + max << endl;
	}
	system("pause");
	return 0;
}

