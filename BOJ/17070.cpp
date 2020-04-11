#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'
#define Y first
#define X second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 16 + 1;

const int scope[3][3][2] = {
	{{0,1}, {0,0}, {1,1}},
	{{0,0}, {1,0}, {1,1}},
	{{0,1}, {1,0}, {1,1}}
};

enum STATE
{
	G,
	S,
	D
};

int house[MAX][MAX];
int N;

int bfs()
{
	queue<pair<int, pii>> q;

	q.push(make_pair(G, make_pair(0, 1)));
	int cnt = 0;
	while (!q.empty())
	{
		int cur_state = q.front().Y;int y = q.front().second.Y; int x = q.front().second.X;
		q.pop();

		if (y == N - 1 && x == N - 1)
		{
			cnt++;
			continue;
		}

		for (int dir = 0; dir < 3; ++dir)
		{
			int ny = y + scope[cur_state][dir][0];
			int nx = x + scope[cur_state][dir][1];
			int ncnt = cnt + 1;

			if (ny == y && nx == x)
				continue;

			if (ny >= N || nx >= N || house[ny][nx] == 1)
				continue;

			if (dir == 2)
			{
				if (house[y][x + 1] == 1 || house[y + 1][x] == 1)
					continue;
			}

			q.push(make_pair(dir, make_pair(ny, nx)));
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cin >> house[y][x];
		}
	}

	int ans = bfs();
	if (ans == -1)
		ans = 0;
	cout << ans << endl;

	return 0;
}
