#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define endl '\n'
#define X second
#define Y first

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
ll N;
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		ans = 0;
		cin >> N;
		while (N != 2) {
			// 제곱근을 먼저 구해본다.
			double tmp = sqrt(N);

			// 제곱근이 정수라면
			if ((int)tmp == tmp) {
				N = (int)tmp;
			}
			else {
				tmp = (int)tmp;
				// N이 만약 7이라면 제곱근은 2.xxx가 된다.
				// 이를 올림하면 3이 되고 이를 제곱해줄경우 9가 나오게 된다.
				// 7이 9가 되기 위한 과정을 9-7을 통하여 계산
				ans += (((tmp + 1) * (tmp + 1)) - N);
				N = (int)sqrt((tmp + 1) * (tmp + 1));
			}
			ans++;
		}
		cout << '#' << t << ' ' << ans << endl;
	}

	return 0;
}
