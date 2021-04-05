#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
const int maxn = 100;
char squ[maxn][maxn];
int M, N;
bool is_out(int r, int c)
{
	if (r >= M || c >= N || r < 0 || c < 0)
		return true;
	return false;
}
void print()
{
	for (int i = 0; i < maxn; ++i)
	{
		for (int j = 0; j < maxn; ++j)
		{
			if (isblank(squ[i][j]))
				break;
			printf("%c", squ[i][j]);
		}			
		printf("\n");
	}
}
int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int Q;
		memset(squ, ' ', sizeof(squ));
		scanf("%d%d%d", &M, &N, &Q);
		printf("%d %d %d\n", M, N, Q);
		// can't use for for loop to scanf char[i][j], because \n in each line
		for (int i = 0; i < M; ++i)
			scanf("%s", squ[i]);
		// print();
		while (Q--)
		{
			int r, c;
			scanf("%d%d", &r, &c);
			int cnt;
			for (cnt = 1; ; ++cnt)
			{
				// check 4: top left, top right, bottom left, bottom right
				if (is_out(r - cnt, c - cnt) || 
					is_out(r - cnt, c + cnt) || 
					is_out(r + cnt, c - cnt) || 
					is_out(r + cnt, c + cnt)	)
					break;
				bool pass = true;
				for (int i = r - cnt; i <= r + cnt; ++i)
					for (int j = c - cnt; j <= c + cnt; ++c)
					{
						if (squ[i][j] != squ[r][c])
						{
							pass = false;
							break;
						}
					}
				if (!pass)
					break;
			}
			printf("%d\n", (--cnt) * 2 + 1);
		}
	}
}
