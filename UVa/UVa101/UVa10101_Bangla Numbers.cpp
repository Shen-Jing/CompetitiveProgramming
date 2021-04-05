
#include <cstdio>
#include <iostream>
using namespace std;
struct BangNum {
	string pattern;
	// magnitude
	int mag;
};
BangNum b_num[4] = {
	{"kuti", 10000000},
	{"lakh", 100000},
	{"hajar", 1000},
	{"shata", 100}	
};

void trans(long long n){
	for (int i = 0; i < 4; ++i){
		if (n >= b_num[i].mag){
			trans(n / b_num[i].mag);
			cout << " " << b_num[i].pattern;
			n %= b_num[i].mag;
		}
	}
	if (n)
		printf(" %lld", n);
}
int main(void){
	long long input;
	int kase = 0;
	while (scanf("%lld", &input) != EOF){
		printf("%4d.", ++kase);
		if (input == 0)
			printf(" 0");
		trans(input);
		printf("\n");
	}
}