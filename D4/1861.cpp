#pragma warning (disable:4996)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
#define ll long long

const int INF = 987654321;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

struct INFO
{
	int room;
	int cnt;
	bool operator<(const INFO& rhs) const
	{
		if (cnt == rhs.cnt)
			return room < rhs.room;
		return cnt > rhs.cnt;
	}
};

int map[1000][1000];
INFO ret[1000 * 1000];
bool visited[1000][1000];
int N;
int ans;

void solve(int sy, int sx, int cnt)
{
	visited[sy][sx] = true;
	for (int dir = 0; dir < 4; ++dir)
	{
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			continue;
		if (map[sy][sx] + 1 == map[ny][nx])
		{
			solve(ny, nx, cnt+1);
		}
	}
	ans = max(ans,cnt);
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		int idx = -1;
		memset(map, 0, sizeof(map));
		memset(ret, 0, sizeof(ret));
		memset(visited, 0, sizeof(visited));
		cin >> N;
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				cin >> map[y][x];
			}
		}

		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < N; ++x)
			{
				if (visited[y][x]) continue;
				for (int dir = 0; dir < 4; ++dir)
				{
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if (ny < 0 || nx < 0 || ny >= N || nx >= N)
						continue;
					if (map[y][x] + 1 == map[ny][nx])
					{
						ans = 0;
						solve(ny, nx,2);
						ret[++idx] = { map[y][x], ans };
					}
				}
			}
		}
		sort(ret, ret + idx + 1);
		cout << '#' << cases << ' ';
		cout << ret[0].room << ' ' << ret[0].cnt << '\n';
	}

	return 0;
}
