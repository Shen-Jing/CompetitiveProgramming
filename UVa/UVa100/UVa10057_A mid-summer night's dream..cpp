#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<int> ans;
		for (auto i = 1; i <= n; ++i)
		{
			int num;
			scanf("%d", &num);
			ans.push_back(num);
		}
		sort(ans.begin(), ans.end());
		
		int mid, mid2;
		if (ans.size() % 2)
			mid = mid2 = ans[ans.size() / 2];
		else
			mid = ans[ans.size() / 2 - 1], mid2 = ans[ans.size() / 2];
		
		/*
		for (const auto & i : ans)
			cout << i << " ";
		cout << endl;
		*/
		
		int cnt = count(ans.begin(), ans.end(), mid), cnt2 = count(ans.begin(), ans.end(), mid2);
		cout << mid << " " 
			 << ((mid == mid2) ? cnt : cnt + cnt2) << " " 
			 << mid2 - mid + 1 << endl;
	}
}