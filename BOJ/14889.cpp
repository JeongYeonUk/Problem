#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int n, ret;
int table[20][20];
int team1[10];
int team2[10];
int pick[20];

void update()
{
	int t1_idx = 0, t2_idx = 0;
	for (int i = 0; i < n; ++i)
	{
		if (pick[i] == 0)
			team1[t1_idx++] = i;
		else
			team2[t2_idx++] = i;
	}
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < (n >> 1); ++i)
	{
		for (int j = i+1; j < (n >> 1); ++j)
		{
			sum1 += (table[team1[i]][team1[j]] + table[team1[j]][team1[i]]);
			sum2 += (table[team2[i]][team2[j]] + table[team2[j]][team2[i]]);
		}
	}
	if (ret > abs(sum1 - sum2))
		ret = abs(sum1 - sum2);
}

void solve(int cur, int pick_count)
{
	if (pick_count == (n >> 1))
	{
		update();
		return;
	}
	for (int i = cur; i < n; ++i)
	{
		pick[i] = 1;
		solve(i + 1, pick_count + 1);
		pick[i] = 0;
	}
}

int main()
{
	scanf("%d", &n);
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			scanf("%d", &table[y][x]);
		}
	}
	ret = INF;
	solve(0,0);
	printf("%d\n", ret);

	return 0;
}
