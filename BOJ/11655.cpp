#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <string>
#include <ostream>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); ++i)
	{
		if (((s[i] - 'A') >= 0) && ((s[i] - 'A') <= 25))
		{
			int temp = s[i] - 'A';
			temp += 13;
			temp %= 26;
			cout << (char)(temp + 'A');
		}
		else if (((s[i] - 'a') >= 0) && ((s[i] - 'a') <= 25))
		{
			int temp = s[i] - 'a';
			temp += 13;
			temp %= 26;
			cout << (char)(temp + 'a');
		}
		else if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9)
		{
			cout << (char)s[i];
		}
		else if (s[i] == ' ')
		{
			cout << (char)s[i];
		}
	}
	return 0;
}
