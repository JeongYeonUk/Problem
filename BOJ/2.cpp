#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

enum STATE
{
	GREEN = 10,
	RED,
	FLOWER
};

struct POS
{
	int y, x;
};

struct INFO
{
	int y, x, state, t;
};

int board[51][51];
POS drag[11];
int N, M, G, R, cnt, ans;
vector<int> v;

int bfs()
{
	int copy[51][51];
	int time[51][51] = { 0, };
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			copy[y][x] = board[y][x];
		}
	}
	queue<INFO> q;
	for (int i = 0; i < cnt; ++i)
	{
		if (v[i] != 0)
		{
			q.push({ drag[i].y, drag[i].x, v[i],0 });
		}
	}

	int candi = 0;
	while (!q.empty())
	{
		int y = q.front().y; int x = q.front().x; int state = q.front().state; int t = q.front().t;
		q.pop();
		if (copy[y][x] == FLOWER)
			continue;
		for (int dir = 0; dir < 4; ++dir)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			int nt = t + 1;
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (copy[ny][nx] == 0 || copy[ny][nx] == FLOWER)
				continue;
			if (state == copy[ny][nx])
				continue;
			if (nt == time[ny][nx])
			{
				if ((state == GREEN) && (copy[ny][nx] == RED))
				{
					copy[ny][nx] = FLOWER;
					candi++;
					continue;
				}
				else if ((state == RED) && (copy[ny][nx] == GREEN))
				{
					copy[ny][nx] = FLOWER;
					candi++;
					continue;
				}
			}
			else
			{
				if (copy[ny][nx] == 1 || copy[ny][nx] == 2)
				{
					copy[ny][nx] = state;
					time[ny][nx] = nt;
					q.push({ ny,nx, state, nt });
				}
			}

		}
	}
	return candi;
}

int main() {
	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d %d", &N, &M, &G, &R);
	int widx = 0;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			scanf("%d", &board[y][x]);
			if (board[y][x] == 2)
			{
				cnt++;
				drag[widx++] = { y, x };
			}
		}
	}

	if ((G + R) != cnt)
	{
		for (int i = 0; i < (cnt - (G + R)); ++i)
		{
			v.push_back(0);
		}
	}
	for (int i = 0; i < G; ++i)
	{
		v.push_back(GREEN);
	}
	for (int i = 0; i < R; ++i)
	{
		v.push_back(RED);
	}

	do
	{
		int candi = bfs();
		if (ans < candi)
			ans = candi;
	} while (next_permutation(v.begin(), v.end()));

	printf("%d\n", ans);

	return 0;
}