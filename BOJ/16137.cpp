#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define endl '\n'

const int MAX = 10 + 1;
const int INF = 987654321;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

int board[MAX][MAX];
int v[MAX][MAX][2];
int N, M;
vector<pair<int, int>> vec;


void print()
{
	for (int y = 1; y <= N; ++y)
	{
		for (int x = 1; x <= N; ++x)
		{
			cout << board[y][x] << " ";
		}
		cout << endl;
	}
}

bool isOut(int y, int x)
{
	return y < 0 || x < 0 || y >= N || x >= N;
}

void set_map()
{
	for (int i = 0, size = (int)vec.size(); i < size; ++i)
	{
		int y = vec[i].first;
		int x = vec[i].second;

		int gcnt = 0;
		for (int dir = 0; dir < 2; ++dir)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (isOut(ny, nx)) continue;
			if (board[ny][nx] == 0 || board[ny][nx] == -1 || board[ny][nx] >= 2)
				gcnt++;
		}
		int scnt = 0;
		for (int dir = 2; dir < 4; ++dir)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (isOut(ny, nx)) continue;
			if (board[ny][nx] == 0 || board[ny][nx] == -1 || board[ny][nx] >= 2)
				scnt++;
		}

		if (gcnt >= 1 && scnt >= 1) board[y][x] = -1;
	}
}

int get_time(int cur_time, int period)
{
	while (true)
	{
		if (cur_time % period == 0) break;
		cur_time++;
	}
	return cur_time;
}

void bfs()
{
	// 0 : y, 1 : x, 2 : bridge, 3 : conti
	queue<tuple<int, int, bool, bool>> q;
	q.push(make_tuple(0, 0, false,  false));
	v[0][0][0] = 0;

	while (!q.empty())
	{
		int y = get<0>(q.front()); int x = get<1>(q.front()); 
		bool bridge = get<2>(q.front()); bool conti = get<3>(q.front());
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			int ntime = v[y][x][bridge] + 1;

			if (isOut(ny, nx)) continue;
			if (board[ny][nx] == -1) continue;

			if (board[ny][nx] == 1 && v[ny][nx][bridge] > ntime)
			{
				v[ny][nx][bridge] = ntime;
				q.push(make_tuple(ny, nx, bridge, false));
			}
			else if (board[ny][nx] == 0)
			{
				if (!bridge && !conti)
				{
					int ttime = get_time(ntime, M);
					if (v[ny][nx][1] > ttime)
					{
						v[ny][nx][1] = ttime;
						q.push(make_tuple(ny, nx, true, true));
					}
				}
			}
			else if (board[ny][nx] >= 2)
			{
				if (!conti)
				{
					int ttime = get_time(ntime, board[ny][nx]);
					if (v[ny][nx][bridge] > ttime)
					{
						v[ny][nx][bridge] = ttime;
						q.push(make_tuple(ny, nx, bridge, true));
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cin >> board[y][x];
			if (!board[y][x])
				vec.push_back(make_pair(y, x));
			v[y][x][0] = INF;
			v[y][x][1] = INF;
		}
	}
	set_map();
	bfs();
	cout << std::min(v[N - 1][N - 1][0], v[N - 1][N - 1][1]) << endl;

	return 0;
}