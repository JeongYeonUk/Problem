#pragma warning (disable:4996)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
#define ll long long

const int INF = 987654321;
int N;
int loc[21][2];
int check[21];
ll ans;

void solve(int idx, int cnt)
{
	if (cnt == N / 2)
	{
		ll xSum = 0; ll ySum = 0;
		for (int i = 0; i < N; ++i)
		{
			if (check[i] == 0)
			{
				xSum += loc[i][0];
				ySum += loc[i][1];
			}
			else
			{
				xSum -= loc[i][0];
				ySum -= loc[i][1];
			}
		}
		if (((xSum * xSum) + (ySum * ySum)) < ans)
			ans = ((xSum * xSum) + (ySum * ySum));
		return;
	}
	for (int i = idx; i < N; ++i)
	{
		if (check[i] == 0)
		{
			check[i] = 1;
			solve(i + 1, cnt + 1);
			check[i] = 0;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		cin >> N;
		memset(loc, 0, sizeof(loc));
		memset(check, 0, sizeof(check));
		for (int i = 0; i < N; ++i)
		{
			cin >> loc[i][0] >> loc[i][1];
		}
		ans = INF;
		solve(0, 0);
		cout << '#' << cases << ' ' << ans << '\n';
	}

	return 0;
}
