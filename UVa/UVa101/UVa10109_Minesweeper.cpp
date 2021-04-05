#include <cstdio>
int row, col;
using namespace std;
bool is_out_of_bound(int r, int c)
{
	if (r >= row || r < 0 || c >= col || c < 0)
		return true;
	return false;
}
char cnt_mine(char ** arr, int cur_r, int cur_c)
{
	auto cnt = 0;
	if (arr[cur_r][cur_c] == '*')
		return '*';
	for (int r = -1; r <= 1; ++r)
		for (int c = -1; c <= 1; ++c)
		{
			if ( is_out_of_bound(cur_r + r, cur_c + c) )
				continue;
			if (arr[cur_r + r][cur_c + c] == '*')
				++cnt;
		}
	return (cnt + '0');
}
int main(void)
{
	auto kase = 1;
	while (scanf("%d%d", &row, &col) != EOF && (row != 0 && col != 0))
	{
		if (kase != 1)
			printf("\n");
		char **arr = new char *[row];
		for (int r = 0; r < row; ++r)
			arr[r] = new char [col];
		
		// eat new line
		getchar();
		for (int r = 0; r < row; ++r)
		{
			for (int c = 0; c < col; ++c)
				arr[r][c] = getchar();
			// eat new line
			getchar();
		}
		
		printf("Field #%d:\n", kase++);
		/*for (int r = 0; r < row; ++r)
		{
			for (int c = 0; c < col; ++c)
				printf("%c", arr[r][c]);
			printf("\n");
		}*/
		
		for (int r = 0; r < row; ++r)
		{
			for (int c = 0; c < col; ++c)
				printf("%c", cnt_mine(arr, r, c));
			printf("\n");
		}
		
		for (int r = 0; r < row; ++r)
			delete [] arr[r];
		delete arr;
	}
}