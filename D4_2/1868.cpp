#pragma warning (disable:4996)
#include <cstdio>
using namespace std;

#define MAX 300

typedef struct _pt
{
	int x; int y;
}PT;

char map[MAX][MAX];

PT Q[MAX * MAX];
int FP, RP;
const int dx[] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[] = { 0,1,1,1,0,-1,-1,-1 };
int N, ans;

inline void enqueue(int a, int b)
{
	Q[FP].y = a; Q[FP++].x = b;
}
inline PT dequeue()
{
	return Q[RP++];
}

int count_mine(int y, int x)
{
	int mine = 0;
	for (int i = 0; i < 8; ++i)
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
	PT temp;
	enqueue(y, x);
	map[y][x] = '0';
	while (RP < FP)
	{
		temp = dequeue();
		for (int i = 0; i < 8; ++i)
		{
			int ny = temp.y + dy[i];
			int nx = temp.x + dx[i];
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
	freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases)
	{
		ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%s", &map[i][0]);
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (map[i][j] == '.' && count_mine(i, j) == 0)
				{
					bfs(i,j);
					ans++;
				}
			}
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (map[i][j] == '.') ans++;
			}
		}
		printf("#%d %d\n", cases, ans);
	}

	return 0;
}
