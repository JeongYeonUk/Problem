#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

struct TREE
{
	int y, x, age;
	bool alive;
};

int n, m, k;
int a[10][10];
int f[10][10];
list<TREE> trees;

const int dx[] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[] = { 0,1,1,1,0,-1,-1,-1 };

int solve()
{
	typedef list<TREE>::iterator ITER;
	for (int year = 0; year < k; ++k)
	{
		for (ITER it = trees.begin(); it != trees.end(); ++it)
		{
			if (it->age <= f[it->y][it->x])
			{
				f[it->y][it->x] -= it->age;
				it->age++;
			}
			else
			{
				it->alive = false;
			}
		}
		for (ITER it = trees.begin(); it != trees.end(); ++it)
		{
			if (it->alive)
				++it;
			else
			{
				f[it->y][it->x] += it->age / 2;
				it = trees.erase(it);
			}
		}
		for (ITER it = trees.begin(); it != trees.end(); ++it)
		{
			if (it->age % 5 == 0)
			{
				for (int dir = 0; dir < 8; ++dir)
				{
					int ny = it->y + dy[dir];
					int nx = it->x + dx[dir];
					if (ny < 0 || nx < 0 || nx >= n || ny >= n)
						continue;
					trees.push_front({ ny,nx,1,true });
				}
			}
		}
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < n; ++x)
			{
				f[y][x] += a[y][x];
			}
		}
	}
	return trees.size();
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			scanf("%d", &a[y][x]);
			f[y][x] = 5;
		}
	}
	int x, y, z;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &y, &x, &z);
		trees.push_back({ y - 1,x - 1,z,true });
	}

	printf("%d\n", solve());

	return 0;
}
