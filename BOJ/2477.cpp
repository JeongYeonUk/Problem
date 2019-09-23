#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int len[6];
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	int x;
	for (int i = 0; i < 6; ++i) {
		cin >> x >> len[i];
	}
	int maxi = 0;
	int idx = 0;
	for (int i = 0; i < 6; ++i) {
		if (maxi < len[i] * len[(i + 1) % 6]) {
			maxi = len[i] * len[(i + 1) % 6];
			idx = i;
		}
	}
	int sum = len[(idx + 3) % 6] * len[(idx + 4) % 6];
	cout << (maxi - sum) * n << endl;
	return 0;
}
