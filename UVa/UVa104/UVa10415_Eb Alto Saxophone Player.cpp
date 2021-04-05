#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct finger
{
	bool press;
	int times;
	finger(bool p = false, int t = 0) : press(p), times(t) {}
};
int main(void)
{
	map <char, vector<int> > notes = {
	{'c', {2, 3, 4, 7, 8, 9, 10}}, {'d', {2, 3, 4, 7, 8, 9}}, {'e', {2, 3, 4, 7, 8}},
	{'f', {2, 3, 4, 7}}, {'g', {2, 3, 4}}, {'a', {2, 3}}, {'b', {2}},
	{'C', {3}}, {'D', {1, 2, 3, 4, 7, 8, 9}}, {'E', {1, 2, 3, 4, 7, 8}}, 
	{'F', {1, 2, 3, 4, 7}}, {'G', {1, 2, 3, 4}}, {'A', {1, 2, 3}}, {'B', {1, 2}}
							};
	int kase;
	cin >> kase;
	// eat new line after kase number
	getchar();
	while (kase--)
	{
		finger * fing = new finger [10];
		string input;
		getline(cin, input);
		// cout << input << endl;
		for (auto & c : input)
		{
			for (int f_i = 1; f_i <= 10; ++f_i)
			{
				auto it = find(notes[c].begin(), notes[c].end(), f_i);
				// not find => don't press
				if (it == notes[c].end())
					fing[f_i - 1].press = false;
				else if (!fing[f_i - 1].press)
						{
							++fing[f_i - 1].times;
							fing[f_i - 1].press = true;
						}
			}
		}
		cout << fing[0].times;
		for (int i = 1; i < 10; ++i)
			cout << " " << fing[i].times;
		cout << endl;
		delete fing;
	}
}