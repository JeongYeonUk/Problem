#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int arr[10];
int tmp[10];
int N;
bool ok() {
	bool flag = true;
	int val = arr[0];
	for (int i = 1; i < N; ++i) {
		if (val != arr[i]) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		memset(arr, 0, sizeof(arr));
		memset(tmp, 0, sizeof(tmp));
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> arr[i];
			if (arr[i] & 1) {
				arr[i]++;
			}
		}

		if (N == 1) {
			cout << "0\n";
			continue;
		}
		else {
			if (ok()) {
				cout << "0\n";
			}
			else {
				int cnt = 1;
				while (true) {
					for (int i = 0; i < N; ++i) {
						tmp[(i + 1) % N] = (arr[i] >> 1);
						arr[i] >>= 1;
					}
					for (int i = 0; i < N; ++i) {
						arr[i] += tmp[i];
						if (arr[i] & 1) {
							arr[i]++;
						}
					}
					if (ok()) {
						cout << cnt << '\n';
						break;
					}
					else {
						cnt++;
					}
				}
			}
		}
	}

	return 0;
}
