#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define endl '\n'
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;

// 1 : 자리수
// 2 : 0 ~ 9
ll dp[13][10];
ll A, B, ans;

int get_len(ll num) {
	int len = 0;
	while (num) {
		len++;
		num /= 10;
	}
	return len;
}

ll solve(ll input, int len, ll mul, ll sum) {
	if (len == 0) {
		return sum;
	}

	int cnt = input / mul;
	ll ans = 0;
	ans += dp[len][cnt];

	return solve(input % mul, len - 1, mul / 10, sum + ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	ll mul = 1;
	for (int i = 1; i < 13; ++i) {
		// 2자리수의 경우
		// 10부터 90을 처리하기에
		// dp[i-1][9] + dp[i-1][1]
		dp[i][1] = dp[i - 1][9] + dp[i - 1][1];
		for (int j = 2; j < 10; ++j) {
			if (j == 5) {
				dp[i][j] += dp[i][j - 1] + mul;
				continue;
			}
			dp[i][j] = dp[i][j - 1] + dp[i][1];
		}
		mul *= 10;
	}

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> A >> B;

		int a_len = get_len(llabs(A));
		int b_len = get_len(llabs(B));

		ll a_num = 1, b_num = 1;
		for (int i = 1; i < a_len; ++i) {
			a_num *= 10;
		}
		for (int i = 1; i < b_len; ++i) {
			b_num *= 10;
		}

		// A가 음수일 경우에
		if ((A >> 63) ^ (B >> 63)) {
			ans = B - A - solve(B, b_len, b_num, 0) - solve(llabs(A), a_len, a_num, 0);
			ans--;
		}
		else {
			ans = B - A;
			ans -= llabs(solve(llabs(A), a_len, a_num, 0) - solve(llabs(B), b_len, b_num, 0));
		}

		cout << '#' << t << " " << ans << endl;
	}

	return 0;
}
