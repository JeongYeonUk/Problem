#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 8;

string map[MAX];
int ans;
int len;
void row(int start)
{
	for (int i = 0; i <= MAX - len; ++i)
	{
		string temp;
		for (int j = i; j < i + len; ++j)
		{
			temp += map[start][j];
		}
		string rev(temp.rbegin(), temp.rend());
		if (temp == rev)
			ans++;
	}
}

void col(int start)
{
	for (int i = 0; i <= MAX - len; ++i)
	{
		string temp;
		for (int j = i; j < i + len; ++j)
		{
			temp += map[j][start];
		}
		string rev(temp.rbegin(), temp.rend());
		if (temp == rev)
			ans++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//int T; cin >> T;
	for (int cases = 1; cases <= 10; ++cases)
	{
		ans = 0;
		cin >> len;
		for (int i = 0; i < MAX; ++i)
		{
			cin >> map[i];
		}
		for (int i = 0; i < MAX; ++i)
		{
			row(i);
			col(i);
		}
		cout << '#' << cases << ' ' << ans << '\n';
	}

	return 0;
}