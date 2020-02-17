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

int rect[4][4], ret[8][3], tmp[8][3];
int ans = 9;

int chk() {
	int val = 1, ret = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (rect[i][j] == val++) {
				ret++;
			}
		}
	}
	return ret;
}

void shift(int k, int a) {
	if (!k) {
		int t = rect[a][3];
		for (int i = 2; i >= 0; --i)
			rect[a][i + 1] = rect[a][i];
		rect[a][0] = t;
	}
	else {
		int t = rect[3][a];
		for (int i = 2; i >= 0; --i)
			rect[i + 1][a] = rect[i][a];
		rect[0][a] = t;
	}
}

void solve(int cnt) {
	if (cnt >= ans || cnt == 8)
		return;
	int candi = chk();
	if (candi == 16) {
		memcpy(ret, tmp, sizeof(ret));
		ans = cnt;
		return;
	}

	if (cnt + 2 >= ans && candi < 12)
		return;
	if (cnt + 3 >= ans && candi < 9)
		return;
	if (cnt + 4 >= ans && candi < 6)
		return;

	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 3; ++j) {
				shift(k, i);
				tmp[cnt][0] = k + 1;
				tmp[cnt][1] = i + 1;
				tmp[cnt][2] = j + 1;
				solve(cnt + 1);
			}
			shift(k, i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> rect[i][j];
		}
	}

	solve(0);
	cout << ans << endl;
	for (int i = 0; i < ans; ++i) {
		cout << ret[i][0] << ' ' << ret[i][1] << ' ' << ret[i][2] << endl;
	}

	return 0;
}
