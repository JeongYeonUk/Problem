#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

struct m
{
	int x; int y;
};

int map[101][101];
int dist[101][101];
bool visit[101][101];
int N, M;
int ret;

void solve(int x, int y)
{
	queue<m> q;
	q.push({ x,y });
	dist[x][y] = 0;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > M || ny > N)
				continue;
			if (map[nx][ny] == 1)
			{
				if (dist[nx][ny] > dist[x][y] + 1)
				{
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx,ny });
				}
			}
			else if (map[nx][ny] == 0)
			{
				if (dist[nx][ny] > dist[x][y])
				{
					dist[nx][ny] = dist[x][y];
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);*/

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%1d", &map[i][j]);
			dist[i][j] = INF;
		}
	}
	solve(1,1);
	printf("%d\n", dist[M][N]);
	return 0;
}
