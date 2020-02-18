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
const int MAX = 100000 + 1;

struct INFO {
	int val, cnt;
};

bool visit[MAX];
int N, K, ans, cnt;

void bfs() {
	queue<INFO> q;
	q.push({ N, 0 });
	visit[N] = true;
	while (!q.empty()) {
		INFO cur = q.front(); q.pop();

		visit[cur.val] = true;

		if (ans && ans == cur.cnt && cur.val == K) {
			cnt++;
		}

		if (!ans && cur.val == K) {
			ans = cur.cnt;
			cnt++;
		}

		if (cur.val - 1 >= 0 && !visit[cur.val - 1]) {
			q.push({ cur.val - 1, cur.cnt + 1 });
		}

		if (cur.val + 1 < MAX && !visit[cur.val + 1]) {
			q.push({ cur.val + 1, cur.cnt + 1 });
		}

		if (cur.val * 2 < MAX && !visit[cur.val * 2]) {
			q.push({ cur.val * 2, cur.cnt + 1 });
		}
		
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> N >> K;

	bfs();

	cout << ans << endl << cnt << endl;

	return 0;
}
