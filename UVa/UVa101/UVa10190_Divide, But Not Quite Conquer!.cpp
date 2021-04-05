#include <vector>
#include <iterator>
#include <cstdio>
using namespace std;
int main(void)
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (m <= 1 || n < m)
		{
			printf("Boring!\n");
			continue;
		}
		vector <int> ans;
		ans.push_back(n);
		bool can_div = true;
		while (n != 1)
		{
			if (n % m == 0)
				ans.push_back(n /= m);
			else
			{
				can_div = false;
				break;
			}
		}
		
		
		if (can_div)
		{
			printf("%d", ans[0]);
			for (vector<int>::iterator it = ans.begin() + 1; it != ans.end(); ++it)
				printf(" %d", *it);
		}
		else
			printf("Boring!");
		printf("\n");
	}
}

