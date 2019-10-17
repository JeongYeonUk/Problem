#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };
struct INFO
{
	int y, x;
};

int map[50][50];
INFO virus[10];
int virus_idx;
int pick[10];
int n, m, ret;

int bfs()
{
	int backup[50][50] = { 0, };
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			backup[y][x] = map[y][x];
		}
	}
	queue<INFO> q;
	for (int i = 0; i < virus_idx; ++i)
	{
		if (pick[i] == 1)
			q.push(virus[i]);
	}
	int ret = 0;
	int size;
	bool is_update;
	while (true)
	{
		is_update = false;
		size = q.size();
		for (int i = 0; i < size; ++i)
		{
			INFO cur = q.front(); q.pop();
			backup[cur.y][cur.x] = 3;
			for (int dir = 0; dir < 4; ++dir)
			{
				INFO next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				if (next.y < 0 || next.x < 0 || next.y >= n || next.x >= n)
					continue;
				if (backup[next.y][next.x] == 2)
				{
					for (int dir = 0; dir < 4; ++dir)
					{
						INFO next_virus;
						next_virus.y = next.y + dy[dir];
						next_virus.x = next.x + dx[dir];
						if (next_virus.y < 0 || next_virus.x < 0 || next_virus.y >= n || next_virus.x >= n)
							continue;
						if (backup[next_virus.y][next_virus.x] == 0)
						{
							q.push(next);
							is_update = true;
							break;
						}
					}
					continue;
				}
				if (backup[next.y][next.x] != 0)
					continue;				
				backup[next.y][next.x] = 3;
				q.push(next);
				is_update = true;
			}
		}	
		if (!is_update)
			break;
		++ret;
	}
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			if (backup[y][x] == 0)
			{
				ret = INF;
				break;
			}
		}
	}
	return ret;
}

void dfs(int cur, int pick_count)
{
	if (pick_count == m)
	{
		int candi = bfs();
		if (ret > candi)
			ret = candi;
		return;
	}
	for (int i = cur; i < virus_idx; ++i)
	{
		pick[i] = 1;
		dfs(i + 1, pick_count + 1);
		pick[i] = 0;
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
				virus[virus_idx++] = { y,x };
			}
		}
	}
	ret = INF;
	dfs(0, 0);
	if (ret == INF)
		ret = -1;
	printf("%d\n", ret);
	return 0;
}
