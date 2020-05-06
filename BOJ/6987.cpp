#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

struct TEAM {
	int win, draw, lose;
};

TEAM t[6];

int solve(int a, int b) {
	if (a == 5) {
		int tw = 0, td = 0, tl = 0;
		for (int i = 0; i < 6; ++i) {
			tw += t[i].win;
			td += t[i].draw;
			tl += t[i].lose;
		}
		if (tw + td + tl == 0)
			return 1;
		else
			return -1;
	}

	int ret = -1;

	if (t[a].win > 0 && t[b].lose > 0) {
		t[a].win--;
		t[b].lose--;

		if (b == 5)
			ret = solve(a + 1, a + 2);
		else
			ret = solve(a, b + 1);

		t[a].win++;
		t[b].lose++;
	}

	if (ret != 1) {
		if (t[a].lose > 0 && t[b].win > 0) {
			t[a].lose--;
			t[b].win--;

			if (b == 5)
				ret = solve(a + 1, a + 2);
			else
				ret = solve(a, b + 1);

			t[a].lose++;
			t[b].win++;
		}
	}

	if (ret != 1) {
		if (t[a].draw > 0 && t[b].draw > 0) {
			t[a].draw--;
			t[b].draw--;

			if (b == 5)
				ret = solve(a + 1, a + 2);
			else
				ret = solve(a, b + 1);

			t[a].draw++;
			t[b].draw++;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 6; ++j) {
			cin >> t[j].win >> t[j].draw >> t[j].lose;
		}

		int ans = solve(0, 1);
		if (ans < 0) {
			cout << 0 << ' ';
		}
		else {
			cout << 1 << ' ';
		}
	}
	cout << endl;
	return 0;
}