#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 10 + 1;

string ma[MAX];
string my[MAX];
int ret[MAX];
int p, q;

bool isMa(int r, int c, int s) {
	int rr = 0, cc = 0, ss = 0;

	for (int i = 0; i < p; ++i) {
		int dot = 0;
		string str = ma[i];
		int j;
		for (j = 0; j < str.length(); ++j) {
			if (str[j] == '.')
				++dot;
			else
				break;
		}

		if (((r * rr) + (c * cc) + (s * ss)) != dot)
			return false;

		for (; j < str.length(); ++j) {
			switch (str[j])
			{
			case '(': ++rr; break;
			case ')': --rr; break;
			case '{': ++cc; break;
			case '}': --cc; break;
			case '[': ++ss; break;
			case ']': --ss; break;
			default:
				break;
			}
		}
	}
	return true;
}

void isMy(int r, int c, int s) {
	int rr = 0, cc = 0, ss = 0;

	for (int i = 0; i < q; ++i) {
		int res = ((r * rr) + (c * cc) + (s * ss));
		if (ret[i] == -2)
			ret[i] = res;
		else if (ret[i] >= 0 && ret[i] != res)
			ret[i] = -1;

		string str = my[i];
		for (int j = 0; j < str.length(); ++j) {
			switch (str[j])
			{
			case '(': ++rr; break;
			case ')': --rr; break;
			case '{': ++cc; break;
			case '}': --cc; break;
			case '[': ++ss; break;
			case ']': --ss; break;
			default:
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> p >> q;
		for (int i = 0; i < p; ++i) {
			cin >> ma[i];
		}
		for (int i = 0; i < q; ++i) {
			cin >> my[i];
		}

		for (int i = 0; i < MAX; ++i) {
			ret[i] = -2;
		}

		for (int r = 1; r <= 20; ++r) {
			for (int c = 1; c <= 20; ++c) {
				for (int s = 1; s <= 20; ++s) {
					if (isMa(r,c,s)) {
						isMy(r,c,s);
					}
				}
			}
		}

		cout << "#" << t << " ";
		for (int i = 0; i < q; ++i) {
			cout << ret[i] << " ";
		}
		cout << endl;
	}

	return 0;
}