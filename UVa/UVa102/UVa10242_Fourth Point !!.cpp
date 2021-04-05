#include <cstdio>
#include <algorithm>
using namespace std;
int main(void)
{
	double coord[4][2] = {0};
	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &coord[0][0], &coord[0][1], &coord[1][0], &coord[1][1], &coord[2][0], &coord[2][1], &coord[3][0], &coord[3][1]) != EOF)
	{
		if (coord[1][0] == coord[2][0] && coord[1][1] == coord[2][1])
			;
		else if (coord[0][0] == coord[2][0] && coord[0][1] == coord[2][1])
			swap(coord[0], coord[1]);
		else if (coord[1][0] == coord[3][0] && coord[1][1] == coord[3][1])
			swap(coord[2], coord[3]);
		else if (coord[0][0] == coord[3][0] && coord[0][1] == coord[3][1])
		{
			swap(coord[0], coord[1]);
			swap(coord[2], coord[3]);
		}
		// printf("%.3lf %.3lf %.3lf\n", coord[0][0], coord[2][0], coord[1][0]);
		printf("%.3lf %.3lf\n", coord[0][0] + coord[3][0] - coord[1][0], coord[0][1] + coord[3][1] - coord[1][1]);
	}
}