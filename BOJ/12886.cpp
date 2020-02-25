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

struct INFO {
	int x, y;
};

int A, B, C, D;
bool check[1000][1000];

void bfs() {
	queue<INFO> q;
	q.push({ A,B });
	check[A][B] = true;
	while (!q.empty()) {
		int x = q.front().x; int y = q.front().y;
		q.pop();
		int z = D - x - y;
		if (x == y && y == z) {
			cout << "1\n";
			return;
		}
		int nx[] = { x,x,y }; int ny[] = { y,z,z };
		for (int i = 0; i < 3; ++i) {
			int a = nx[i]; int b = ny[i];
			if (a < b) {
				b -= a;
				a += a;
			}
			else if (a > b) {
				a -= b;
				b += b;
			}
			else {
				continue;
			}
			int c = D - a - b;
			int X = min({ a,b,c });
			int Y = max({ a,b,c });
			if (!check[X][Y]) {
				check[X][Y] = true;
				q.push({ X,Y });
			}
		}
	}
	cout << "0\n";
}

void solve() {
	if (D % 3) {
		cout << "0\n";
		return;
	}
	else {
		bfs();
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	cin >> A >> B >> C;
	D = A + B + C;
	solve();

	return 0;
}
