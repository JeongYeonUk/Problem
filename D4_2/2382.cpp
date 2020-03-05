#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAXN = 100 + 1;
const int MAXK = 1000 + 1;

const int dy[] = { 0,-1,1,0,0 };
const int dx[] = { 0,0,0,-1,1 };

struct INFO {
	int y, x, cnt, dir;
	bool alive;
};

int board[MAXN][MAXN];
deque<INFO> bugMap[MAXN][MAXN];
vector<INFO> bug;
int N, M, K;

void init() {
	memset(board, 0, sizeof(board));
	for (int y = 0; y < MAXN; ++y) {
		for (int x = 0; x < MAXN; ++x) {
			bugMap[y][x].clear();
		}
	}
	bug.clear();
}

void flipDir(int& dir) {
	switch (dir)
	{
	case 1: dir = 2; break;
	case 2: dir = 1; break;
	case 3: dir = 4; break;
	case 4: dir = 3; break;
	default:
		break;
	}
}

void simul() {

	// 살아있는 미생물들을 순서대로 옮겨야함
	int bugSize = (int)bug.size();
	for (int i = 0; i < bugSize; ++i) {
		if (!bug[i].alive)
			continue;

		bugMap[bug[i].y][bug[i].x].pop_front();

		// 방향에 따라 이동
		int ny = bug[i].y + dy[bug[i].dir];
		int nx = bug[i].x + dx[bug[i].dir];
		// 만약에 약품이 칠해져 있다면
		if (board[ny][nx] == 1) {
			// 미생물 수 반으로 감소, 방향 반대로
			bug[i].cnt >>= 1;
			// 미생물 수가 0이라면 해당 미생물 사망
			if (!bug[i].cnt) {
				bug[i].alive = false;
				continue;
			}
			flipDir(bug[i].dir);
		}

		// bugMap에 표시
		bugMap[ny][nx].push_back({ ny,nx,bug[i].cnt, bug[i].dir, bug[i].alive });
		// bug 위치 이동
		bug[i].y = ny;
		bug[i].x = nx;
	}

	// 중첩된 미생물들을 하나로 합치는 작업
	// 미생물들의 합
	int bugSum = 0;
	// 가장 많은 미생물
	int bugMax = -1;
	// 가장 많은 미생물의 방향
	int bugDir = 0;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			// bugMap을 순회해서 size가 1 이상일 경우
			if (bugMap[y][x].size() > 1) {
				int bugMapSize = bugMap[y][x].size();
				bugSum = 0;
				bugMax = -1;
				bugDir = 0;
				for (int i = 0; i < bugMapSize; ++i) {
					bugSum += bugMap[y][x][i].cnt;
					if (bugMax < bugMap[y][x][i].cnt) {
						bugMax = bugMap[y][x][i].cnt;
						bugDir = bugMap[y][x][i].dir;
					}
				}
				for (int i = 0; i < bugSize; ++i) {
					// 좌표가 같은데 최대 값이랑 다르면 죽임
					if (bug[i].y == y && bug[i].x == x) {
						if (bug[i].cnt != bugMax) {
							bug[i].alive = false;
						}
						// 최대 값이랑 같으면 값 갱신
						else {
							bug[i].cnt = bugSum;
							bug[i].dir = bugDir;
						}
					}
				}
				// bugMap 갱신
				bugMap[y][x].clear();
				bugMap[y][x].push_back({ y,x,bugSum, bugDir, true });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("input.txt", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		init();
		cin >> N >> M >> K;
		// 가장자리 약품 칠하기
		for (int y = 0; y < N; ++y) {
			board[y][0] = board[y][N - 1] = 1;
		}
		for (int x = 0; x < N; ++x) {
			board[0][x] = board[N - 1][x] = 1;
		}

		// 입력 받기
		for (int k = 0; k < K; ++k) {
			INFO input;
			input.alive = true;
			cin >> input.y >> input.x >> input.cnt >> input.dir;
			bug.push_back(input);
			bugMap[input.y][input.x].push_back(input);
		}

		// M 시간동안 시물레이션
		for (int m = 0; m < M; ++m) {
			simul();
		}

		// 답 도출
		int bugSize = (int)bug.size();
		int ans = 0;
		for (int i = 0; i < bugSize; ++i) {
			if (!bug[i].alive)
				continue;
			ans += bug[i].cnt;
		}
		cout << "#" << t << " " << ans << endl;
	}

	return 0;
}