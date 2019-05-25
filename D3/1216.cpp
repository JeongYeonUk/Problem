#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string rmap[100];
string cmap[100];
int rans;
int cans;

bool palindrome(string str)
{
	string s(str.rbegin(), str.rend());
	if (s == str)
		return true;
	else
		return false;
}

void rsolve(int index)
{
	string str = rmap[index];
	int pos = 0;
	while (pos != 50)
	{
		string check(str.begin() + pos, str.end() - pos);
		int max = (int)check.length();
		if (palindrome(check))
		{
			if (max > rans)
				rans = max;
		}
		pos++;
	}
}

void csolve(int index)
{
	string str = cmap[index];
	int pos = 0;
	while (pos != 50)
	{
		string check(str.begin() + pos, str.end() - pos);
		int max = (int)check.length();
		if (palindrome(check))
		{
			if (max > cans)
				cans = max;
		}
		pos++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	for (int cases = 1; cases <= 10; ++cases)
	{
		int T; cin >> T;
		rans = cans = 0;
		for (int i = 0; i < 100; ++i)
		{
			cin >> rmap[i];
		}
		for (int i = 0; i < 100; ++i)
		{
			string temp;
			for (int j = 0; j < 100; ++j)
			{
				temp += rmap[j][i];
			}
			cmap[i] = temp;
		}
		for (int i = 0; i < 100; ++i)
		{
			rsolve(i);
			csolve(i);
		}
		cout << '#' << cases << ' ' << (rans > cans ? rans : cans) << '\n';
	}

	return 0;
}