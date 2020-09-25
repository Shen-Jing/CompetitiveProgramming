#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
void init(int * arr, int tmp){
	for (int i = 0; tmp; ++i){
		arr[i] = tmp % 10;
		tmp /= 10;
	}
}

int main(void){
	int cnt;
	string s_num1, s_num2;
	while (cin >> s_num1 >> s_num2){
		int num1 = stoi(s_num1), num2 = stoi(s_num2);
		if (num1 == 0 && num2 == 0)
			break;
		int len1 = s_num1.size(), len2 = s_num2.size();
		int n = (len1 > len2) ? len1 : len2;
		int arr1[n + 1], arr2[n + 1];
		
		memset(arr1, 0, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));
		init(arr1, num1);
		init(arr2, num2);
		
		// simulate operaion
		int cnt = 0;
		for (int i = 0; i <= n; ++i){
			arr1[i] += arr2[i];
			if (arr1[i] >= 10){
				arr1[i] %= 10;
				arr1[i + 1] += 1;
				++cnt;
			}
		}
		
		if (cnt == 0)
			printf("No carry operation.\n");
		else if (cnt == 1)
			printf("%d carry operation.\n", cnt);
		else
			printf("%d carry operations.\n", cnt);
	}
}