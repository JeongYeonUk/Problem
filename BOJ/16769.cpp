#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

struct INFO {
	int cut;
	int milk;
};

INFO info[3];

void solve() {
	for (int i = 0; i < 100; ++i) {
		int now = i % 3;
		int next = (now + 1) % 3;
		int tmp = info[now].milk + info[next].milk;
		info[now].milk = (info[next].cut <= tmp ? tmp - info[next].cut : 0);
		info[next].milk = (info[next].cut <= tmp ? info[next].cut : tmp);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 3; ++i) {
		cin >> info[i].cut >> info[i].milk;
	}

	solve();

	for (int i = 0; i < 3; ++i) {
		cout << info[i].milk << endl;
	}

	return 0;
}
