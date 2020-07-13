#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll tt[100001];
int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n >> m;

		ll imax = 0;
		for (int nn = 0; nn < n; ++nn) {
			cin >> tt[nn];
			if (imax < tt[nn]) imax = tt[nn];
		}

		ll left = 1, right = imax * m;
		ll result = imax * m;
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll total = 0;
			for (int i = 0; i < n; ++i) {
				total += mid / tt[i];
			}

			if (total < m) {
				left = mid + 1;
			}
			else {
				if (result > mid) result = mid;
				right = mid - 1;
			}
		}
		cout << "#" << t << " " << result << endl;
	}

	return 0;
}
