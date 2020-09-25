#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
#include <memory>
using namespace std;
const int maxn = 10000;
int main(void){
	int kase, n, sum;
	scanf("%d", &kase);
	for (int k = 1; k <= kase; ++k){
		scanf("%d", &n);
		// unique_ptr<int []> f(new int [n]);
		int f[maxn];
		for (int i = 0; i < n; ++i)
			scanf("%d", &f[i]);
		sort(f, f + n);
		
		int ans;
		for (int i = 0; i < n; ++i){
			int sum = 0;
			int tmp_pos = f[i];
			for (int j = 0; j < n; ++j)
				sum += abs(tmp_pos - f[j]);
			if (i == 0)
				ans = sum;
			if (sum < ans)
				ans = sum;
		}
		printf("%d\n", ans);
	}
}