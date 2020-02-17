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
const int MAX = 2000000 + 5;

int dp[MAX];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int gap = 5, cur = 1, n, mmn = 100000;
	v.push_back(cur);

	for (;; gap += 4) {
		cur = cur + gap;
		if (cur > 1000000)
			break;
		v.push_back(cur);
	}
	dp[1] = 1;
	for (int i = 2; i <= MAX; ++i)
		dp[i] = 1000000;
	for (int i = 2; i <= 130; ++i) {
		for (int j = 0; j < (int)v.size(); ++j) {
			if (i < v[j])
				break;
			dp[i] = min(dp[i], dp[i - v[j]] + 1);
		}
	}

	cin >> n;
	if (n <= 130) {
		cout << dp[n] << endl;
		return 0;
	}

	for (int i = 0; i < (int)v.size(); ++i) {
		dp[v[i]] = 1;
	}
	for (int i = 0; i < (int)v.size(); ++i) {
		for (int j = 0; j < (int)v.size(); ++j) {
			int vv = v[i] + v[j];
			dp[vv] = min(dp[vv], 2);
		}
	}

	for (int i = 0; i <= n; ++i) {
		if (dp[i] + dp[n - i] < mmn) {
			mmn = dp[i] + dp[n - i];
		}
	}
	cout << mmn << endl;
	return 0;
}
