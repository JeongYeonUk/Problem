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

	// 3154 �� ��
	// 30** �̸� tight 0
	// 31** �̸� tight 1
	// �� ��° �ڸ��� 0�̸� 3��° �ڸ��� 0 ~ 9 ���� �� �� �ְ�
	// �� ��° �ڸ��� 1�̸� 3��° �ڸ��� 0 ~ 5 ���� �� �� �ִ�.
	int k = tight ? digit[idx] : 9;

	// �������� ���ϴ� �ݺ���
	for (int i = 0; i <= k; ++i) {
		int ntight = (digit[idx] == i) ? tight : 0;
		ret += solve(idx - 1, sum + i, ntight, digit);
	}

	// tight�� 0�� ���� ������Ʈ
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