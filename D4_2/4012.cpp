#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'
#define abs(x) ((x) > 0 ? (x) : -(x))
#define rint register int
typedef long long ll;

const int INF = 987654321;
const int MAX = 16 + 1;

bool visit[MAX];
int syn[MAX][MAX];
int N, ans;

int solve() {
	int A = 0, B = 0, aidx = 0, bidx = 0;
	int arrA[MAX];
	int arrB[MAX];
	for (rint i = 0; i < N; ++i) {
		if (visit[i])
			arrA[aidx++] = i;
		else
			arrB[bidx++] = i;
	}

	for (rint i = 0; i < (N >> 1) - 1; ++i) {
		for (rint j = i + 1; j < (N >> 1); ++j) {
			A += syn[arrA[i]][arrA[j]] + syn[arrA[j]][arrA[i]];
			B += syn[arrB[i]][arrB[j]] + syn[arrB[j]][arrB[i]];
		}
	}
	return abs(A - B);
}

void dfs(int idx, int cnt) {
	if (cnt == (N >> 1)) {
		int candi = solve();
		if (candi < ans)
			ans = candi;
		return;
	}

	for (rint i = idx; i < N; ++i) {
		visit[i] = true;
		dfs(i + 1, cnt + 1);
		visit[i] = false;
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);

	for (rint cases = 1; cases <= T; ++cases) {
		ans = INF;
		memset(visit, false, sizeof(visit));
		scanf("%d", &N);
		for (rint i = 0; i < N; ++i)for (rint j = 0; j < N; ++j) scanf("%d", &syn[i][j]);
		dfs(0, 0);
		printf("#%d %d\n", cases, ans);
	}

	return 0;
}