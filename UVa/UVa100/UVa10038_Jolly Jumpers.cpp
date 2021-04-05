#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	string input;
	while (getline(cin, input))
	{
		stringstream ss(input);
		unsigned int n;
		auto fir{0}, sec{0};
		ss >> n >> fir;
		// only one number
		if (n == 1)
		{
			printf("Jolly\n");
			continue;
		}
		
		if (n == 2)
		{
			ss >> sec;
			if (abs(fir - sec) != 1)
				printf("Not jolly\n");
			else
				printf("Jolly\n");
			continue;
		}
		vector<int> ans;
		bool pass = true;
		for (auto i = 1; i <= n - 1; ++i)
		{
			ss >> sec;
			auto diff = abs(fir - sec);
			if (diff > n - 1 || find(ans.begin(), ans.end(), diff) != ans.end())
			{
				pass = false;
				break;
			}
			ans.push_back(diff);
			fir = sec;
		}
		if (pass)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
}