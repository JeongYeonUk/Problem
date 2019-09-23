#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 100001;

int arr[MAX_N];
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	if (N < 3) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	int ans = -1;
	for (int d1 = -1; d1 <= 1; ++d1) {
		for (int d2 = -1; d2 <= 1; ++d2) {
			int cnt = 0;
			if (d1 != 0) cnt += 1;
			if (d2 != 0) cnt += 1;
			int a0 = arr[0] + d1;
			int diff = (arr[1] + d2) - a0;
			int an = a0 + diff;
			bool flag = true;
			for (int i = 2; i < N; ++i) {
				an += diff;
				if (arr[i] == an) continue;
				if (arr[i] + 1 == an) {
					cnt += 1;
				}
				else if (arr[i] - 1 == an) {
					cnt += 1;
				}
				else {
					flag = false;
					break;
				}
			}
			if (flag) {
				if (ans == -1 || ans > cnt) {
					ans = cnt;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
