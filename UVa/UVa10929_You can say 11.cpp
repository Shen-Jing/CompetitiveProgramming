
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
int main(void){
	string input;
	while (cin >> input){
		int n = input.size();
		// odd / even position sum
		int ops = 0, eps = 0;
		
		if (input[0] == '0' && n == 1)
			break;
		
		for (int i = 0; i < n; i += 2){
			eps += input[i] - '0';
			if (i + 1 < n)
				ops += input[i + 1] - '0';
		}
		if ((ops - eps) % 11 == 0)
			cout << input << " is a multiple of 11.\n";
		else 
			cout << input << " is not a multiple of 11.\n";
	}
	
	return 0;
}

