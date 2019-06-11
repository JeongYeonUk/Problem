#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
int map[51][51];
bool visit[51][51];
int N, M, K;
int ans;

void dfs(int y, int x)
{
	if (visit[y][x]) return;
	visit[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < M && 0 <= ny && ny < N)
			if (map[ny][nx])
				dfs(ny, nx);
	}
}
int main()
{
	int T; scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases)
	{
		for (int i = 0; i <= 50; ++i)
		{
			for (int j = 0; j <= 50; ++j)
			{
				map[i][j] = 0;
				visit[i][j] = false;
			}
		}
		ans = 0;
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < K; ++i)
		{
			int x, y; scanf("%d %d", &y, &x);
			map[y][x] = 1;
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (map[i][j] == 1 && !visit[i][j])
				{
					ans++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
