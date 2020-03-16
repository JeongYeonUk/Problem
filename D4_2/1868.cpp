#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

#define MAX 301
#define rint register int

struct POS
{
	int x; int y;
};

char map[MAX][MAX];

POS Q[MAX * MAX];
int FP, RP;
const int dx[] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[] = { 0,1,1,1,0,-1,-1,-1 };
int N, ans;

inline void enqueue(int a, int b)
{
	Q[FP].y = a; Q[FP++].x = b;
}
inline POS dequeue()
{
	return Q[RP++];
}

int count_mine(int y, int x)
{
	int mine = 0;
	for (rint i = 0; i < 8; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (map[ny][nx] == '*')
			mine++;
	}
	return mine;
}

void bfs(int y, int x)
{
	FP = RP = 0;
	int mine = 0;
	POS cur;
	enqueue(y, x);
	map[y][x] = '0';
	while (RP < FP)
	{
		cur = dequeue();
		for (rint i = 0; i < 8; ++i)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (map[ny][nx] == '.')
			{
				mine = count_mine(ny, nx);
				if (mine == 0) enqueue(ny, nx);
				map[ny][nx] = mine + '0';
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);
	for (rint cases = 1; cases <= T; ++cases)
	{
		ans = 0;
		scanf("%d", &N);
		for (rint i = 0; i < N; ++i)
		{
			scanf("%s", &map[i][0]);
		}
		for (rint i = 0; i < N; ++i)
		{
			for (rint j = 0; j < N; ++j)
			{
				if (map[i][j] == '.' && count_mine(i, j) == 0)
				{
					bfs(i, j);
					ans++;
				}
			}
		}
		for (rint i = 0; i < N; ++i)
		{
			for (rint j = 0; j < N; ++j)
			{
				if (map[i][j] == '.') ans++;
			}
		}
		printf("#%d %d\n", cases, ans);
	}

	return 0;
}
