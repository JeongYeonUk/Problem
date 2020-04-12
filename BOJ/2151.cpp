#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define Y first
#define X second
#define DIR first
#define MIRROR second
#define endl '\n'

typedef pair<int, int> pii;

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

const int MAX = 50 + 1;
const int INF = 987654321;

int visit[MAX][MAX][4];
char board[MAX][MAX];
int N;

pii src, dest;

void print(int sy, int sx, int mirror)
{
	cout << mirror << endl;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (y == sy && x == sx)
			{
				cout << '$';
			}
			else
			{
				cout << board[y][x];
			}
		}
		cout << endl;
	}
	cout << endl;
}

void init()
{
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			for (int i = 0; i < 4; ++i)
			{
				visit[y][x][i] = INF;
			}
		}
	}
}

int bfs()
{
	queue<pair<pii, pii>> q;
	q.push(make_pair(src, make_pair(0, 0)));
	q.push(make_pair(src, make_pair(1, 0)));
	q.push(make_pair(src, make_pair(2, 0)));
	q.push(make_pair(src, make_pair(3, 0)));

	init();

	visit[src.Y][src.X][0] = 0;
	visit[src.Y][src.X][1] = 0;
	visit[src.Y][src.X][2] = 0;
	visit[src.Y][src.X][3] = 0;

	int candi = INF;

	while (!q.empty())
	{
		int y = q.front().first.Y; int x = q.front().first.X;
		int cur_dir = q.front().second.DIR; int cur_mirror = q.front().second.MIRROR;
		q.pop();

		//print(y, x, cur_mirror);

		if (dest.Y == y && dest.X == x) 
		{
			if (cur_mirror < candi)
				candi = cur_mirror;
			continue;
		}

		for (int dir = 0; dir < 4; ++dir)
		{
			if (cur_dir != dir) continue;

			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (board[ny][nx] == '*') continue;
			if (visit[ny][nx][cur_dir] < cur_mirror) continue;

			if (board[ny][nx] == '.' || board[ny][nx] == '#')
			{
				visit[ny][nx][cur_dir] = cur_mirror;
				q.push(make_pair(make_pair(ny,nx), make_pair(cur_dir, cur_mirror)));
			}
			else if (board[ny][nx] == '!')
			{
				visit[ny][nx][cur_dir] = cur_mirror;
				// 거울 설치 안한 경우
				q.push(make_pair(make_pair(ny, nx), make_pair(cur_dir, cur_mirror)));

				// 거울 설치 한 경우
				switch (cur_dir)
				{
				// right, left
				case 0:
				case 1:
					q.push(make_pair(make_pair(ny, nx), make_pair(2, cur_mirror + 1)));
					q.push(make_pair(make_pair(ny, nx), make_pair(3, cur_mirror + 1)));
					break;
				// down
				// up
				case 2:
				case 3:
					q.push(make_pair(make_pair(ny, nx), make_pair(0, cur_mirror + 1)));
					q.push(make_pair(make_pair(ny, nx), make_pair(1, cur_mirror + 1)));
					break;
				default:
					break;
				}
			}
		}
	}
	return candi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N;
	bool flag = true;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cin >> board[y][x];
			if (board[y][x] == '#')
			{
				if (flag)
					src = make_pair(y, x), flag = false;
				else
					dest = make_pair(y, x);
			}
		}
	}

	int ans = bfs();
	if (ans == INF)
		ans = 0;
	cout << ans << endl;

	return 0;
}