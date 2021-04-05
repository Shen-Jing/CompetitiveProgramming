#include <map>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(void){
	map<string, int> ans;
	
	int n;
	string input;
	scanf("%d", &n);
	cin.ignore(100, '\n');
	for (int i = 1; i <= n; ++i){
		getline(cin, input);
		
		int pos = input.find(' ');
		string country = input.substr(0, pos);
		if (!ans.count(country))
			ans[country] = 0;
		++ans[country];
	}
	
	for (auto const& i: ans){
		cout << i.first << " ";
		cout << i.second << endl;
	}
}