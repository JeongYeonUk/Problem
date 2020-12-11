#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'
#define INF 987654321

struct INFO {
	int y, x, dir;
};

int N, K;

int grid[13][13];			// 타일 상태 확인
INFO chess[11];				// 체스 말 상태 (y 좌표, x 좌표, 방향)
vector<int> pos[13][13];	// 위치 정보 저장

const int dy[] = {0,0,-1,1};
const int dx[] = {1,-1,0,0};

bool is_end()
{
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if ((int)pos[y][x].size() >= 4) return true;
		}
	}
	return false;
}

int change_dir(int dir)
{
	switch (dir)
	{
	case 0: return 1;
	case 1: return 0;
	case 2: return 3;
	case 3: return 2;
	}
}

vector<int> search_chess(int y, int x, int val)
{
	vector<int> tmp = pos[y][x];
	pos[y][x].clear();

	int size = (int)tmp.size();
	int i;
	for (i = 0; i < size; ++i) {
		if (tmp[i] == val) break;
	}
	for (int j = 0; j < i; ++j) {
		pos[y][x].push_back(tmp[j]);
	}
	vector<int> ret;
	for (; i < size; ++i) {
		ret.push_back(tmp[i]);
	}

	return ret;
}

void move_chess(int idx, int cy, int cx, int ny, int nx, int dir, vector<int> moving)
{
	int size = (int)moving.size();
	if (ny < 0 || nx < 0 || ny >= N || nx >= N || grid[ny][nx] == 2) {
		chess[idx].dir = dir;
		for (int i = 0; i < size; ++i) {
			chess[moving[i]].y = cy;
			chess[moving[i]].x = cx;
			pos[cy][cx].push_back(moving[i]);
		}
		return;
	}

	int state = grid[ny][nx];
	switch (state)
	{
	case 0: {
		chess[idx].y = ny; chess[idx].x = nx; chess[idx].dir = dir;
		for (int i = 0; i < size; ++i) {
			chess[moving[i]].y = ny;
			chess[moving[i]].x = nx;
			pos[ny][nx].push_back(moving[i]);
		}
		break;
	}
	case 1: {
		chess[idx].y = ny; chess[idx].x = nx; chess[idx].dir = dir;
		reverse(moving.begin(), moving.end());
		for (int i = 0; i < size; ++i) {
			chess[moving[i]].y = ny;
			chess[moving[i]].x = nx;
			pos[ny][nx].push_back(moving[i]);
		}
		break;
	}
	default:
		break;
	}
}

int solve()
{
	for (int time = 1; time <= 1000; ++time) {
		for (int i = 0; i < K; ++i) {
			INFO cur = chess[i];
			vector<int> moving = search_chess(cur.y, cur.x, i);

			int ny = cur.y + dy[cur.dir];
			int nx = cur.x + dx[cur.dir];
			int ndir = cur.dir;
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || grid[ny][nx] == 2) {
				ndir = change_dir(ndir);
				ny = cur.y + dy[ndir];
				nx = cur.x + dx[ndir];
			}
			move_chess(i, cur.y, cur.x, ny, nx, ndir, moving);
			if (is_end()) return time;
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < K; ++i) {
		INFO input;
		cin >> input.y >> input.x >> input.dir;
		input.y -= 1;
		input.x -= 1;
		input.dir -= 1;

		pos[input.y][input.x].push_back(i);

		chess[i] = input;
	}

	int ans = solve();
	cout << ans << endl;

	return 0;
}
