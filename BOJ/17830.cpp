#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

int solve(const string& str) {
	int cnt = 0, idx = -1, size = (int)str.size();
	for (int i = size - 1; i >= 0; --i) {
		if (str[i] == '1') {
			cnt++;
			if (idx == -1) idx = i;
		}
	}
	if (cnt == 0) return 1;
	return N + idx + (cnt > 1 ? 1 : 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		string str, a, b;
		cin >> N >> str;
		a = b = str;

		for (int i = 0, size = (int)str.size(); i < size; ++i) {
			if (str[i] == '?') {
				a[i] = '1';
				b[i] = '0';
			}
		}

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		cout << solve(a) << " " << solve(b) << endl;
	}

	return 0;
}
