#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX = 50000 + 1;

ll arr[MAX];
ll l, r, N;
ll ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> N;
		ans = 0;
		for (int i = 0; i < N; ++i) {
			cin >> arr[i];
		}
		l = r = 0;

		// 왼쪽 숫자 개수와 오른쪽 숫자 개수를 곱해주면 된다.
		//	1		4		6		5		3		7			9		2		8
		//			l++		l++		r++		r++		reset,l++	l++		r++		reset
		for (int i = 1; i < N; ++i) {
			if (r > 0 && l == 0 && arr[i - 1] < arr[i])
				r = 0;
			if (l > 0 && r > 0 && arr[i - 1] < arr[i]) {
				ans += l * r;
				l = r = 0;
			}
			if (arr[i - 1] < arr[i])
				l++;
			if (arr[i] < arr[i - 1])
				r++;
		}
		if (l > 0 && r > 0)
			ans += l * r;
		cout << "#" << t << " " << ans << endl;
	}

	return 0;
}