#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

struct INFO
{
	int y, x;
};

int map[50][50];
vector<INFO> home, chick, pick;
int n, m, ret;

int dist(INFO a, INFO b)
{
	return abs(a.y - b.y) + abs(a.x - b.x);
}

void dfs(int cur)
{
	if (pick.size() == m)
	{
		int candi = 0;
		for (int i = 0; i < (int)home.size(); ++i)
		{
			int min_dist = INF;
			for (int j = 0; j < (int)pick.size(); ++j)
			{
				int delta = dist(home[i], pick[j]);
				if (min_dist > delta)
					min_dist = delta;
			}
			candi += min_dist;
		}

		if (ret > candi)
			ret = candi;
		return;
	}
	for (int i = cur; i < chick.size(); ++i)
	{
		pick.push_back(chick[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			scanf("%d", &map[y][x]);
			if (map[y][x] == 2)
			{
				chick.push_back({ y,x });
			}
			if (map[y][x] == 1)
			{
				home.push_back({ y,x });
			}
		}
	}

	ret = INF;
	dfs(0);
	printf("%d\n", ret);
	return 0;
}
