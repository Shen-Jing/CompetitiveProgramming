#include <cstdio>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <cmath>
using namespace std;
const int max_range = 1000000;
bool prime[max_range];
int main(void)
{
	// create prime table
	fill(begin(prime), end(prime), true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= max_range; ++i)
	{
		if (prime[i])
			for (int j = i * i; j < max_range; j += i)
				prime[j] = false;
	}
	/*
	for (int i = 0; i <= 30; ++i)
		if (prime[i])
			cout << i << " ";
	*/
	string str_N;
	while (cin >> str_N)
	{
		int N = stoi(str_N);
		reverse(str_N.begin(), str_N.end());
		int rev_N = stoi(str_N);
		// cout << N << ", " << rev_N << endl;
		if (prime[N])
		{
			if (N == rev_N || !prime[rev_N])
				cout << N << " is prime.\n";
			else
				cout << N << " is emirp.\n";
		}
		else
			cout << N << " is not prime.\n";
	}
}