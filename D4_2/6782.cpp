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
			// �������� ���� ���غ���.
			double tmp = sqrt(N);

			// �������� �������
			if ((int)tmp == tmp) {
				N = (int)tmp;
			}
			else {
				tmp = (int)tmp;
				// N�� ���� 7�̶�� �������� 2.xxx�� �ȴ�.
				// �̸� �ø��ϸ� 3�� �ǰ� �̸� �������ٰ�� 9�� ������ �ȴ�.
				// 7�� 9�� �Ǳ� ���� ������ 9-7�� ���Ͽ� ���
				ans += (((tmp + 1) * (tmp + 1)) - N);
				N = (int)sqrt((tmp + 1) * (tmp + 1));
			}
			ans++;
		}
		cout << '#' << t << ' ' << ans << endl;
	}

	return 0;
}
