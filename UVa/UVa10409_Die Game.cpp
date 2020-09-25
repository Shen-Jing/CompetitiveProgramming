#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		auto top = 1, north = 2, west = 3;
		while (n--)
		{
			string dir;
			cin >> dir;
			
			auto tmp = top;
			switch (dir[0])
			{
				case 'n':
					top = 7 - north;
					north = tmp;
					break;
				case 's':
					top = north;
					north = 7 - tmp;
					break;
				case 'w':
					top = 7 - west;
					west = tmp;
					break;
				case 'e':
					top = west;
					west = 7 - tmp;
					break;
				default:
					break;
			}
			// printf("t: %d, n: %d, w: %d\n", top, north, west);
		}
		printf("%d\n", top);
	}
}