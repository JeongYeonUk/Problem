#pragma warning(disable:4996)
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

struct Pos {
	int dir, dist;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int M, N; cin >> M >> N;
	int T; cin >> T; T++;
	vector<Pos> vec;
	while (T--) {
		int a, b; cin >> a >> b;
		if (a == 4) b = b + M;
		else if (a == 2) b = M + N + (M - b);
		else if (a == 3) b = 2 * M + N + (N - b);
		vec.push_back({ a,b });
	}
	Pos dong = vec.back();
	int ret = 0;
	for (int i = 0; i < (int)vec.size() - 1; ++i) {
		int path = abs(dong.dist - vec[i].dist);
		ret += min(path, 2 * (M + N) - path);
	}
	cout << ret << endl;
	return 0;
}
