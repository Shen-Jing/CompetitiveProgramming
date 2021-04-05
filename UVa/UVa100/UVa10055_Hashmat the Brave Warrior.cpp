#include <cstdio>
#include <cmath>
using namespace std;
int main(void){
	long long mine, yours;
	while (scanf("%lld%lld", &mine, &yours) != EOF){
		long long ans = abs(mine - yours);
		printf("%lld\n", ans);
	}
}