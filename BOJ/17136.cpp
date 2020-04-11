#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int paper[6] = { 0,5,5,5,5,5 };
int board[11][11];
int ans;

bool is_possible(int size, int y, int x)
{
	if (y + size > 10 || x + size > 10)
		return false;
	for (int yy = y; yy < y + size; ++yy)
	{
		for (int xx = x; xx < x + size; ++xx)
		{
			if (board[yy][xx] == 0)
				return false;
		}
	}
	return true;
}


void attach(int size, int y, int x)
{
	for (int yy = y; yy < y + size; ++yy)
	{
		for (int xx = x; xx < x + size; ++xx)
		{
			board[yy][xx] ^= 1;
		}
	}

}

void print()
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			cout << board[y][x] << " ";
		}
		cout << endl;
	}
}

void solve(int idx, int cnt)
{
	if (idx == 100)
	{
		if (cnt < ans)
			ans = cnt;
		return;
	}

	int y = idx / 10;
	int x = idx % 10;

	if (ans <= cnt)
		return;

	if (board[y][x])
	{
		for (int i = 5; i >= 1; --i)
		{
			if (paper[i] > 0)
			{
				if (is_possible(i, y, x))
				{
					attach(i, y, x);
					paper[i]--;
					solve(idx + 1, cnt + 1);
					attach(i, y, x);
					paper[i]++;
				}
			}
		}
	}
	else
	{
		solve(idx + 1, cnt);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			cin >> board[y][x];
		}
	}

	ans = 100;
	solve(0, 0);
	if (ans == 100)
		ans = -1;
	cout << ans << endl;

	return 0;
}
