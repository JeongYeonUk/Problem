#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int n, r, c;
int ret;

void solve(int x, int y, int len) {
	if (len == 2) {
		if (y == r && x == c) {
			cout << ret << endl;
			return;
		}
		ret++;
		if (y == r && x + 1 == c) {
			cout << ret << endl;
			return;
		}
		ret++;
		if (y + 1 == r && x == c) {
			cout << ret << endl;
			return;
		}
		ret++;
		if (y + 1 == r && x + 1 == c) {
			cout << ret << endl;
			return;
		}
		ret++;
		return;
	}
	solve(x, y, len / 2);
	solve(x + len / 2, y, len / 2);
	solve(x, y + len / 2, len / 2);
	solve(x + len / 2, y + len / 2, len / 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> r >> c;

	solve(0, 0, 1 << n);

	return 0;
}
