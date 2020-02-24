#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 100000 + 5;

struct INFO {
	int cur, curLine, cnt;
};

int N, K;
bool visit[2][MAX];
string l, r;
int idx;

int bfs() {
	queue<INFO> q;
	q.push({ 0,0,-1 });
	visit[0][0] = true;
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();
		int nCnt = cur.cnt + 1;
		if (cur.cur >= N) {
			return 1;
		}
		l[nCnt] = r[nCnt] = '0';

		if (cur.cur - 1 > 0 && !visit[cur.curLine][cur.cur - 1]) {
			visit[cur.curLine][cur.cur - 1] = true;
			if (cur.curLine) {
				if (r[cur.cur - 1] != '0') {
					q.push({ cur.cur - 1, cur.curLine, nCnt });
				}
			}
			else {
				if (l[cur.cur - 1] != '0') {
					q.push({ cur.cur - 1, cur.curLine, nCnt });
				}
			}
		}

		if (!visit[cur.curLine][cur.cur + 1]) {
			if (cur.cur + 1 >= N) {
				q.push({ cur.cur + 1, cur.curLine, nCnt });
				continue;
			}
			visit[cur.curLine][cur.cur + 1] = true;
			if (cur.curLine) {
				if (r[cur.cur + 1] != '0') {
					q.push({ cur.cur + 1, cur.curLine, nCnt });
				}
			}
			else {
				if (l[cur.cur + 1] != '0') {
					q.push({ cur.cur + 1, cur.curLine, nCnt });
				}
			}
		}

		if (!visit[cur.curLine ^ 1][cur.cur + K]) {
			if (cur.cur + K >= N) {
				q.push({ cur.cur + K, cur.curLine ^ 1, nCnt });
				continue;
			}
			visit[cur.curLine ^ 1][cur.cur + K] = true;
			if (cur.curLine) {
				if (l[cur.cur + K] != '0') {
					q.push({ cur.cur + K, cur.curLine ^ 1, nCnt });
				}
			}
			else {
				if (r[cur.cur + K] != '0') {
					q.push({ cur.cur + K, cur.curLine ^ 1, nCnt });
				}
			}
		}
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> N >> K;
	cin >> l >> r;

	idx = -1;
	cout << bfs() << endl;

	return 0;
}
