#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const double PI = 2 * acos(0);
inline double deg_to_rad(double deg)
{
	return deg / 180 * PI;
}
int main(void)
{
	int s;
	double a;
	string str_a;
	while (cin >> s >> a >> str_a)
	{
		s += 6440;
		double angle;
		if (str_a == "min")
			angle = a / 60;
		else
			angle = a;
		angle = min(360 - angle, angle);
		double rad_ang = deg_to_rad(angle);
		// cosin principle
		/*
		double chord = sqrt(2 * s * s
							* ( 1 - cos(rad_ang) )
							);
		*/						
		// sin principle
		double chord = sin(rad_ang) * s / sin(deg_to_rad((180 - angle) / 2));
		cout << fixed << setprecision(6) << 2 * s * PI * angle / 360 << " "
										 << chord << '\n';
	}
}