#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <iostream>
enum Orient {
	Nor, Sou, Eas, Wes
};
enum Dir {
	Lef, Rig
};
// direction and forward
struct DaF {
	// N, S, E, W
	// forward x
	int fx[4] = {0, 0, 1, -1},
		fy[4] = {1, -1, 0, 0};
};
// char instruction to int value
int c_to_i(char c)
{
	switch (c)
	{
		case 'N':
			return Nor;
		case 'S':
			return Sou;
		case 'E':
			return Eas;
		case 'W':
			return Wes;
		case 'L':
			return Lef;
		case 'R':
			return Rig;
	}
}
using namespace std;
int main(void)
{
	// change orientation {ori, {after Left, after Right}...}
	map<int, vector<char> > cha_ori = 
					{
						{Nor, {'W', 'E'}}, 
						{Eas, {'N', 'S'}}, 
						{Sou, {'E', 'W'}},
						{Wes, {'S', 'N'}},
					};
	bool scent[51][51];
	memset(scent, false, sizeof(scent));
	// max x, max y
	int mx, my;
	int x, y;
	char dir;
	DaF daf;
	scanf("%d %d", &mx, &my);
	// cout << cha_ori[Nor][Lef];
	while (scanf("%d %d %c ", &x, &y, &dir) != EOF)
	{
		// printf("%d %d %c\n", x, y, d);
		bool lost = false;
		string input;
		getline(cin, input);
		for (const auto & ins : input)
		{
			if (isspace(ins))
				continue;
			if (ins == 'F')
			{
				// test if out of the world
				if (x + daf.fx[c_to_i(dir)] > mx || x + daf.fx[c_to_i(dir)] < 0 || y + daf.fy[c_to_i(dir)] > my || y + daf.fy[c_to_i(dir)] < 0)
				{
					// is new scent => drop off the world
					if (!scent[x][y])
					{
						// scent.push_back({x, y});
						scent[x][y] = true;
						lost = true;
						break;
					}
					else // old scent
					{
						continue;
					}
				}
				x += daf.fx[c_to_i(dir)];
				y += daf.fy[c_to_i(dir)];
			}
			else
			{
				dir = cha_ori[c_to_i(dir)][c_to_i(ins)];
			}
		}
		cout << x << " " << y << " " << dir;
		if (lost)
			cout << " LOST";
		cout << '\n';
	}
}