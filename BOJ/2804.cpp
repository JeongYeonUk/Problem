#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	string a, b; cin >> a >> b;
	int alen = a.length();
	int blen = b.length();
	int x = 0, y = 0;
	for (int i = 0; i < alen; ++i) {
		bool flag = true;
		for (int j = 0; j < blen; ++j) {
			if (a[i] == b[j]) {
				y = j;
				x = i;
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}

	for (int i = 0; i < blen; ++i) {
		for (int j = 0; j < alen; ++j) {
			if (j == x && i != y) {
				cout << b[i];
			}
			else if (i == y) {
				cout << a[j];
			}
			else {
				cout << ".";
			}
		}
		cout << "\n";
	}

	return 0;
}
