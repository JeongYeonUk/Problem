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

	// ����ִ� �̻������� ������� �Űܾ���
	int bugSize = (int)bug.size();
	for (int i = 0; i < bugSize; ++i) {
		if (!bug[i].alive)
			continue;

		bugMap[bug[i].y][bug[i].x].pop_front();

		// ���⿡ ���� �̵�
		int ny = bug[i].y + dy[bug[i].dir];
		int nx = bug[i].x + dx[bug[i].dir];
		// ���࿡ ��ǰ�� ĥ���� �ִٸ�
		if (board[ny][nx] == 1) {
			// �̻��� �� ������ ����, ���� �ݴ��
			bug[i].cnt >>= 1;
			// �̻��� ���� 0�̶�� �ش� �̻��� ���
			if (!bug[i].cnt) {
				bug[i].alive = false;
				continue;
			}
			flipDir(bug[i].dir);
		}

		// bugMap�� ǥ��
		bugMap[ny][nx].push_back({ ny,nx,bug[i].cnt, bug[i].dir, bug[i].alive });
		// bug ��ġ �̵�
		bug[i].y = ny;
		bug[i].x = nx;
	}

	// ��ø�� �̻������� �ϳ��� ��ġ�� �۾�
	// �̻������� ��
	int bugSum = 0;
	// ���� ���� �̻���
	int bugMax = -1;
	// ���� ���� �̻����� ����
	int bugDir = 0;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			// bugMap�� ��ȸ�ؼ� size�� 1 �̻��� ���
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
					// ��ǥ�� ������ �ִ� ���̶� �ٸ��� ����
					if (bug[i].y == y && bug[i].x == x) {
						if (bug[i].cnt != bugMax) {
							bug[i].alive = false;
						}
						// �ִ� ���̶� ������ �� ����
						else {
							bug[i].cnt = bugSum;
							bug[i].dir = bugDir;
						}
					}
				}
				// bugMap ����
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
		// �����ڸ� ��ǰ ĥ�ϱ�
		for (int y = 0; y < N; ++y) {
			board[y][0] = board[y][N - 1] = 1;
		}
		for (int x = 0; x < N; ++x) {
			board[0][x] = board[N - 1][x] = 1;
		}

		// �Է� �ޱ�
		for (int k = 0; k < K; ++k) {
			INFO input;
			input.alive = true;
			cin >> input.y >> input.x >> input.cnt >> input.dir;
			bug.push_back(input);
			bugMap[input.y][input.x].push_back(input);
		}

		// M �ð����� �ù����̼�
		for (int m = 0; m < M; ++m) {
			simul();
		}

		// �� ����
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