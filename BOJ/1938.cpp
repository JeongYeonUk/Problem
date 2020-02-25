#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 50 + 5;

const int dy[] = { 0,0,1,-1,1,1,-1, -1 };
const int dx[] = { 1,-1,0,0,1,-1,1,-1 };

enum DIR {
	RIGHT,
	LEFT,
	DOWN,
	UP
};

struct POS {
	int y, x;

	const bool operator==(const POS& rhs) const {
		if (this->y == rhs.y && this->x == rhs.x) {
			return true;
		}
		return false;
	}
};

struct INFO {
	POS left;
	POS center;
	POS right;
	int cnt;
};

char board[MAX][MAX];
bool lvisit[MAX][MAX];
bool cvisit[MAX][MAX];
bool rvisit[MAX][MAX];
int N;
INFO src, dest;

bool isIn(POS pos) {
	if (pos.y < 0 || pos.x < 0 || pos.y >= N || pos.x >= N || board[pos.y][pos.x] == '1')
		return false;
	return true;
}

//void copymap(char src[][MAX], char dest[][MAX]) {
//	for (int y = 0; y < N; ++y) {
//		for (int x = 0; x < N; ++x) {
//			if (src[y][x] == 'B' || src[y][x] == 'E') {
//				dest[y][x] = '0';
//			}
//			else {
//				dest[y][x] = src[y][x];
//			}
//		}
//	}
//}
//
//void print(char out[][MAX]) {
//	for (int y = 0; y < N; ++y) {
//		for (int x = 0; x < N; ++x) {
//			cout << out[y][x];
//		}
//		cout << endl;
//	}
//	cout << endl;
//}

int bfs() {
	queue<INFO> q;
	q.push(src);
	lvisit[src.left.y][src.left.x] = cvisit[src.center.y][src.center.x] = rvisit[src.right.y][src.right.x] = true;

	while (!q.empty()) {
		//char out[MAX][MAX]; memset(out, 0, sizeof(out));
		//copymap(board, out);
		POS left = q.front().left; POS center = q.front().center; POS right = q.front().right;
		int cnt = q.front().cnt;
		q.pop();

		//out[left.y][left.x] = out[center.y][center.x] = out[right.y][right.x] = 'B';
		//print(out);

		if (left == dest.left && center == dest.center && right == dest.right) {
			return cnt;
		}

		for (int dir = 0; dir < 4; ++dir) {
			POS nleft = { left.y + dy[dir], left.x + dx[dir] };
			POS ncenter = { center.y + dy[dir], center.x + dx[dir] };
			POS nright = { right.y + dy[dir], right.x + dx[dir] };
			int ncnt = cnt + 1;

			if (!(isIn(nleft) & isIn(ncenter) & isIn(nright)))
				continue;
			if (lvisit[nleft.y][nleft.x] && cvisit[ncenter.y][ncenter.x] && rvisit[nright.y][nright.x])
				continue;

			lvisit[nleft.y][nleft.x] = cvisit[ncenter.y][ncenter.x] = rvisit[nright.y][nright.x] = true;
			q.push({ nleft, ncenter, nright, ncnt });
		}

		// 회전 가능 여부
		bool flag = true;
		for (int dir = 0; dir < 8; ++dir) {
			POS next = { center.y + dy[dir], center.x + dx[dir] };
			if (!isIn(next)) {
				flag = false;
				break;
			}
		}

		// 회전
		if (flag) {
			// 수평일때
			if (left.y == center.y) {
				POS nup = { center.y + dy[UP], center.x + dx[UP] };
				POS ndown = { center.y + dy[DOWN], center.x + dx[DOWN] };
				if (lvisit[nup.y][nup.x] && rvisit[ndown.y][ndown.x])
					continue;
				lvisit[nup.y][nup.x] = rvisit[ndown.y][ndown.x] = true;
				q.push({ nup, center, ndown, cnt + 1 });
			}
			// 수직일때
			else {
				POS nleft = { center.y + dy[LEFT], center.x + dx[LEFT] };
				POS nright = { center.y + dy[RIGHT], center.x + dx[RIGHT] };
				if (lvisit[nleft.y][nleft.x] && rvisit[nright.y][nright.x])
					continue;
				lvisit[nleft.y][nleft.x] = rvisit[nright.y][nright.x] = true;
				q.push({ nleft, center, nright, cnt + 1 });
			}
		}

	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> N;
	int bcnt = 0, ecnt = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> board[y][x];
			if (board[y][x] == 'B') {
				if (bcnt == 0) {
					bcnt++;
					src.left = { y,x };
				}
				else if (bcnt == 1) {
					bcnt++;
					src.center = { y,x };
				}
				else if (bcnt == 2) {
					src.right = { y,x };
				}
			}
			else if (board[y][x] == 'E') {
				if (ecnt == 0) {
					ecnt++;
					dest.left = { y,x };
				}
				else if (ecnt == 1) {
					ecnt++;
					dest.center = { y,x };
				}
				else if (ecnt == 2) {
					dest.right = { y,x };
				}
			}
		}
	}

	cout << bfs() << endl;

	return 0;
}
