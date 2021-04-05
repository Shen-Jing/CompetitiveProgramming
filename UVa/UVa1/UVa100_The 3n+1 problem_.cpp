#include <cstdio>
#include <climits>
using namespace std;
void swap(int& a, int& b){
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int main(void){
	int num1, num2, low, high;
	while (scanf("%d%d", &num1, &num2) != EOF){
		int cnt, max_cnt = 0;
		
		if (num1 > num2){
			low = num2;
			high = num1;
		}
		else {
			low = num1;
			high = num2;
		}
		for (int i = low; i <= high; ++i){
			int tmp = i;
			cnt = 1;
			while (tmp != 1){
				if (tmp % 2 == 1)
					tmp = 3 * tmp + 1;
				else
					tmp /= 2;
				++cnt;
			}
			if (max_cnt < cnt)
				max_cnt = cnt;
		}
		printf("%d %d %d\n", num1, num2, max_cnt);
	}
	return 0;
}
