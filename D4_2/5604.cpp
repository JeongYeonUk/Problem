#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

// idx, sum, tight
ll dp[16][150][2];
ll a, b;
int aidx, bidx;
int A[20];
int B[20];

ll solve(int idx, int sum, int tight, int* digit) {
	if (idx == -1)
		return sum;

	ll& tmp = dp[idx][sum][tight];
	if (tmp != -1 && !tight)
		return tmp;

	ll ret = 0;

	// 3154 일 때
	// 30** 이면 tight 0
	// 31** 이면 tight 1
	// 두 번째 자리가 0이면 3번째 자리가 0 ~ 9 까지 올 수 있고
	// 두 번째 자리가 1이면 3번째 자리가 0 ~ 5 까지 올 수 있다.
	int k = tight ? digit[idx] : 9;

	// 누적합을 구하는 반복문
	for (int i = 0; i <= k; ++i) {
		int ntight = (digit[idx] == i) ? tight : 0;
		ret += solve(idx - 1, sum + i, ntight, digit);
	}

	// tight가 0일 때만 업데이트
	if (!tight)
		tmp = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);

	int t; scanf("%d", &t);
	for (int cases = 1; cases <= t; ++cases) {
		memset(dp, -1, sizeof(dp));
		scanf("%lld %lld", &a, &b);
		aidx = 0, bidx = 0;
		if (a) a--;
		while (a) {
			A[aidx++] = (a % 10);
			a /= 10;
		}
		while (b) {
			B[bidx++] = (b % 10);
			b /= 10;
		}
		ll ans = (solve(bidx - 1, 0, 1, B) - solve(aidx - 1, 0, 1, A));
		printf("#%d %lld\n", cases, ans);
	}

	return 0;
}