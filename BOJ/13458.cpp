#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 1000001;

ll arr[MAX_N];
ll dp[MAX_N];
ll N, B, C;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	cin >> B >> C;
	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	ll tmp;
	ll mok, na;
	for (int i = 1; i <= N; ++i) {
		ll ret = 0;
		if (dp[i] != -1) {
			ans += dp[i];
			continue;
		}
		if (arr[i] <= B) {
			ret++;
		}
		else {
			tmp = arr[i] - B;
			ret++;
			if (tmp <= C) {
				ret++;
			}
			else {
				mok = tmp / C;
				na = tmp % C;
				if (na != 0) {
					mok += 1;
				}
				ret += mok;
			}
		}
		dp[i] = ret;
		ans += ret;
	}

	cout << ans << '\n';

	return 0;
}
