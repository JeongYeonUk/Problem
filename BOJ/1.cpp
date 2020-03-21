#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

struct POS
{
	int y, x;
};

int board[101][101];
int sti[100][10][10];
int stiSize[100][2];
bool visit[41][41];
int N, M, K, R, C, ans;

void init()
{
	for (int y = 0; y < 101; ++y)
	{
		for (int x = 0; x < 101; ++x)
		{
			board[y][x] = -1;
		}
	}
	for (int y = 0; y < N; ++y)
	{
		for (int x = 10; x < 10 + M; ++x)
		{
			board[y][x] = 0;
		}
	}
}
void rotate(int k)
{
	int rr = stiSize[k][0];
	int cc = stiSize[k][1];
	int n = rr > cc ? rr : cc;

	int tmp[10][10] = { 0, };
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			tmp[r][c] = sti[k][n - c - 1][r];
		}
	}
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			sti[k][r][c] = tmp[r][c];
		}
	}
}

bool check(int y, int x, int k)
{
	int rr = stiSize[k][0];
	int cc = stiSize[k][1];
	int n = rr > cc ? rr : cc;
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{			
			if (board[y + r][x + c] != 0 && sti[k][r][c] == 1)
				return false;
		}
	}

	return true;
}


void attach(int y, int x, int k)
{
	int rr = stiSize[k][0];
	int cc = stiSize[k][1];
	int n = rr > cc ? rr : cc;
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			if(!board[y+r][x+c])
				board[y + r][x + c] = sti[k][r][c];
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &N, &M, &K);

	for (int k = 0; k < K; ++k)
	{
		scanf("%d %d", &R, &C);
		stiSize[k][0] = R;
		stiSize[k][1] = C;
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				scanf("%d", &sti[k][r][c]);
			}
		}
	}
	init();
	
	bool flag = true;
	for (int k = 0; k < K; ++k)
	{
		for (int dir = 0; dir < 4; ++dir)
		{	
			flag = false;
			for (int y = 0; y < N; ++y)
			{
				for (int x = 0; x < 10 + M; ++x)
				{
					if (check(y, x, k))
					{
						attach(y, x, k);
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
			else
			{
				rotate(k);
			}
		}
	}
	
	for (int y = 0; y < N; ++y)
	{
		for (int x = 10; x < 10 + M; ++x)
		{
			if (board[y][x])
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}