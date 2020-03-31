#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
#define X second
#define Y first

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX = 100000 + 1;

vector<int> road;
bool visited[MAX];
int parent[MAX]; // 경로 추적을 위한 parent 배열
int N, K;

int bfs() {
	queue<pii> q;
	// Y = cur, X = sec;
	q.push(make_pair(N, 0));
	visited[N] = true;

	while (!q.empty()) {
		int cur = q.front().Y; int sec = q.front().X;
		q.pop();

		if (cur == K) {
			int idx = cur;
			while (idx != N) {
				road.push_back(idx);
				idx = parent[idx];
			}
			road.push_back(N);
			return sec;
		}

		if (cur + 1 < MAX && !visited[cur + 1]) {
			visited[cur + 1] = true;
			parent[cur + 1] = cur;
			q.push(make_pair(cur + 1, sec + 1));
		}

		if (cur - 1 >= 0 && !visited[cur - 1]) {
			visited[cur - 1] = true;
			parent[cur - 1] = cur;
			q.push(make_pair(cur - 1, sec + 1));
		}

		if ((cur << 1) < MAX && !visited[(cur << 1)]) {
			visited[(cur << 1)] = true;
			parent[(cur << 1)] = cur;
			q.push(make_pair(cur << 1, sec + 1));
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> K;
	cout << bfs() << endl;

	int size = road.size();
	for (int i = size - 1; i >= 0; --i) {
		cout << road[i] << ' ';
	}
	cout << endl;

	return 0;
}
