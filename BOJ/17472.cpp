#pragma warning(disable:4996)
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

struct Edge
{
	int s, e, x;
	Edge(){}
	Edge(int s, int e, int x) : s(s), e(e), x(x){}
	bool operator< (const Edge& rhs) const
	{
		return x < rhs.x;
	}
};

struct INFO
{
	int y, x;
};

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

int n, m;
int map[10][10];
int label[10][10];
vector<Edge> edge;
vector<INFO> v[10];

void bfs(int sy, int sx, int number)
{
	queue<INFO> q; q.push({ sy,sx });
	label[sy][sx] = number;
	v[number].push_back({ sy,sx });
	while (!q.empty())
	{
		INFO cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir)
		{
			INFO next;
			next.y = cur.y + dy[dir];
			next.x = cur.x + dx[dir];
			if (next.y < 0 || next.x < 0 || next.y >= n || next.x >= m)
				continue;
			if (!map[next.y][next.x] || label[next.y][next.x])
				continue;
			label[next.y][next.x] = number;
			v[number].push_back({ next.y,next.x });
			q.push({ next.y, next.x });
		}
	}
}

void bridge(int sy, int sx, int dir)
{
	int s = label[sy][sx];
	int cnt = 0;
	while (true)
	{
		sy += dy[dir];
		sx += dx[dir];
		cnt++;
		if (sy < 0 || sx < 0 || sy >= n || sx >= m)
			break;
		if (!label[sy][sx])
			continue;
		if (cnt - 1 != 1)
			edge.push_back({ s,label[sy][sx], cnt - 1 });
		break;
	}
}

int p[11];
int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

bool merge(int u, int v)
{
	u = find(u); v = find(v);
	if (u == v)
		return false;
	p[u] = v;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			scanf("%d", &map[y][x]);
		}
	}
	int number = 0;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			if (!label[y][x] && map[y][x])
				bfs(y, x, ++number);
		}
	}

	for (int i = 1; i <= number; ++i)
	{
		for (auto t : v[i])
		{
			for (int dir = 0; dir < 4; ++dir)
			{
				bridge(t.y, t.x, dir);
			}
		}
	}

	sort(edge.begin(), edge.end());
	int ans = 0, cnt = 0;
	for (int i = 0; i < 11; ++i)
	{
		p[i] = i;
	}
	for (auto i : edge)
	{
		int s = i.s, e = i.e, x = i.x;
		if (merge(s, e))
		{
			ans += x;
			cnt++;
		}
	}
	if (cnt != number - 1)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}
