#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define DEBUG 0
using namespace std;
int main(void){
	short n, numA, numB;
	struct findResult{
		// 第幾堆 
		short row;
		// 的第幾個(array index)
		short col;
	}a, b;
	
	while (scanf("%d", &n) != EOF){
		string action1, action2;
		int i, j;
		short block[25][25];
		// 初始化為-1: 沒有block 
		memset(block, -1, sizeof(block));
		
		// 初始化每列的第一個元素，其他為-1(沒放block) 
		for (i = 0; i < n; i++){
			block[i][0] = i;
		}
		
		while (cin >> action1 && action1 != "quit"){
			cin >> numA >> action2 >> numB;
			// 尋找每一堆，定位a, b尚未動作前在何處 
			for (i = 0; i < n; i++){
				short result_a = find(block[i], block[i] + n, numA) - block[i],
					result_b = find(block[i], block[i] + n, numB) - block[i];
					
				if (result_a != n){
					// 若 != n => 此堆有找到a
					a.row = i;
					a.col = result_a;
				}
				
				if (result_b != n){
					b.row = i;
					b.col = result_b;
				}
			}
			// 若a, b在同一堆 => illegal command => 不用繼續動作，繼續下個文字指令 
			if (a.row == b.row)
				continue;
			
			// 若能來到此，開始移動block 
			// 若是move => numA上方的一定要歸位 
			if (action1 == "move"){
				// 從numA所在那堆的col以後，將非-1的block歸位 
				for (i = a.col + 1; block[a.row][i] != -1 && i < n; i++){
					// 要被歸位的那個磚塊的原本所在堆的index 
					short moved_i = block[a.row][i];
					
					// 找到空的位置，放入block 
					block[moved_i][find(block[moved_i], block[moved_i] + n, -1) - block[moved_i]] = moved_i;
					// 標記為空的狀態 
					block[a.row][i] = -1;
				}
			}
			#if DEBUG == 1
			for (i = 0; i < n; i++){
			printf("%d: ", i);
				for (j = 0; j < n && block[i][j] != -1; j++){
					printf("%d ", block[i][j]);
				}
				printf("\n");
			}
			cout << endl;
			#endif
			// 若是onto => b上頭的木塊就要歸位 
			if (action2 == "onto"){
				// 從numB所在那堆的col以後，將非-1的block歸位 
				for (i = b.col + 1; block[b.row][i] != -1 && i < n; i++){
					// 要被歸位的那個磚塊的原本所在堆的index 
					short moved_i = block[b.row][i];
					
					// 找到空的位置，放入block 
					block[moved_i][find(block[moved_i], block[moved_i] + n, -1) - block[moved_i]] = moved_i;
					// 標記為空的狀態 
					block[b.row][i] = -1;
				}
			}
			#if DEBUG == 1
			for (i = 0; i < n; i++){
			printf("%d: ", i);
				for (j = 0; j < n && block[i][j] != -1; j++){
					printf("%d ", block[i][j]);
				}
				printf("\n");
			}
			cout << endl;
			#endif
			// 接著將numA移動到numB，上頭因為已經處理完numA、numB上頭block需不需要移動的可能情況
			// 接續動作一定是numA到numB
			
			// 計算到上頭有多少個block也要一起移動，記錄第一個空的index 
			short Ato = find(block[a.row], block[a.row] + n, -1) - block[a.row],
				Bto = find(block[b.row], block[b.row] + n, -1) - block[b.row];
				
			// 因此，numA移動時：不包括記錄到的index
			// 但是Bto是numB上頭第一個空的，因此從此開始「放」 
			// 則從a_i開始搬，搬到Ato(不含)
			int a_i, b_i;
			for (a_i = a.col, b_i = Bto; a_i < Ato; a_i++, b_i++){
				block[b.row][b_i] = block[a.row][a_i];
				block[a.row][a_i] = -1;
			}
			#if DEBUG == 1
			for (i = 0; i < n; i++){
			printf("%d: ", i);
				for (j = 0; j < n && block[i][j] != -1; j++){
					printf("%d ", block[i][j]);
				}
				printf("\n");
			}
			cout << endl;
			#endif
		}
		// quit後印出所有元素 
		for (i = 0; i < n; i++){
			printf("%d: ", i);
			for (j = 0; j < n && block[i][j] != -1; j++){
				printf("%d ", block[i][j]);
			}
			printf("\n");
		}
	}
	
	
	system("pause");
	return 0;
}

