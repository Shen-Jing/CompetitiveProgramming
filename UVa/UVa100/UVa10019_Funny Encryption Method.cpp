#include <string>
#include <cstdio>
#include <bitset>
using namespace std;
int main(void)
{
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		int m;
		scanf("%d", &m);
		string str_m = to_string(m);
		int x1 = m, x2 = stoi(str_m, nullptr, 16);
		// to binary string
		bitset<16> bin1(x1), bin2(x2);
		// caculate how many 1
		int b1 = bin1.count(), b2 = bin2.count();
		printf("%d %d\n", b1, b2);
	}
}