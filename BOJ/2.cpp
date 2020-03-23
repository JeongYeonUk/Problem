#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
#define X second
#define Y first

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int garden[51][51];
int N, M, G, R, ans;

vector<pii> candi;
int canSz;
int brute[10];

int bfs() {

	int cnt = 0;
	pii state[51][51]; // Y : time, X : state

	queue<pii> q;
	for (int i = 0; i < canSz; ++i) {
		if (brute[i] == GREEN || brute[i] == RED) {
			state[candi[i].Y][candi[i].X] = make_pair(0, brute[i]);
			q.push(candi[i]);
		}
	}

	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		int curtime = state[cur.Y][cur.X].Y;
		int curstate = state[cur.Y][cur.X].X;
		if (curstate == FLOWER)
			continue;
		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.Y + dy[dir];
			int nx = cur.X + dx[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (garden[ny][nx] == 0)
				continue;

			if (state[ny][nx].X == EMPTY) {
				state[ny][nx] = make_pair(curtime + 1, curstate);
				q.push(make_pair(ny, nx));
			}
			else if (state[ny][nx].X == RED) {
				if (curstate == GREEN && curtime + 1 == state[ny][nx].Y) {
					cnt++;
					state[ny][nx].X = FLOWER;
				}
			}
			else if (state[ny][nx].X == GREEN) {
				if (curstate == RED && curtime + 1 == state[ny][nx].Y) {
					cnt++;
					state[ny][nx].X = FLOWER;
				}
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> M >> G >> R;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> garden[y][x];
			if (garden[y][x] == 2) {
				candi.push_back(make_pair(y, x));
			}
		}
	}
	
	canSz = candi.size();

	fill(brute + canSz - G - R, brute + canSz - R, GREEN);
	fill(brute + canSz - R, brute + canSz, RED);

	do {
		ans = max(ans, bfs());
	} while (next_permutation(brute, brute + canSz));
	cout << ans << endl;
	return 0;
}