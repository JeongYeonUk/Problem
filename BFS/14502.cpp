#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

typedef struct _point
{
	int x; int y;
}Point;

int N, M;
int lab[8][8];
int ans;
Point q[100];
int fp, rp;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

void bfs()
{
	int spread[8][8];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			spread[i][j] = lab[i][j];	
			if (spread[i][j] == 2)
			{
				q[fp].x = j;
				q[fp].y = i;
				fp = (fp + 1) % 100;
			}
		}
	}
	
	while (fp != rp)
	{
		int x = q[rp].x;
		int y = q[rp].y;
		rp = (rp + 1) % 100;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 > nx || M <= nx || 0 > ny || N <= ny) continue;
			if (spread[ny][nx] == 0)
			{
				spread[ny][nx] = 2;
				q[fp].x = nx;
				q[fp].y = ny;
				fp = (fp + 1) % 100;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (spread[i][j] == 0)
				cnt++;
		}
	}
	if (ans < cnt)
		ans = cnt;
}

void makeWall(int cnt)
{
	if (cnt == 3)
	{
		bfs();
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (lab[i][j] == 0)
			{
				lab[i][j] = 1;
				makeWall(cnt + 1);
				lab[i][j] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &lab[i][j]);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (lab[i][j] == 0)
			{				
				lab[i][j] = 1;
				makeWall(1);
				lab[i][j] = 0;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
