#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 20000 + 5;

bool visit[MAX];
int p[MAX];
map<int, char> m;
int N;

void bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = true;
	p[1] = -1;
	m[1] = '1';

	/*
	나머지에 0과 1을 덧붙이면 몫에도 동일한 수가 덧붙여 진다
	나머지에 0과 1을 덧붙인 후 다시 n을 나누면 몫에 0과 1을 덧붙여 나눈것과 동일하다.	
	*/


	while (!q.empty()) {
		int cur = q.front(); q.pop();

		int newNums[2];

		newNums[0] = (cur * 10) % N;
		newNums[1] = (newNums[0] + 1) % N;

		for (int i = 0; i < 2; ++i) {
			if (!visit[newNums[i]]) {
				m[newNums[i]] = i + '0';
				p[newNums[i]] = cur;
				if (!newNums[i])
					return;
				visit[newNums[i]] = true;
				q.push(newNums[i]);
			}
		}
	}
}

void printPath(int num) {
	if (num == -1)
		return;
	printPath(p[num]);
	cout << m[num];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> N;
		if (N == 1) {
			cout << "1\n";
			continue;
		}
		memset(visit, false, sizeof(visit));

		bfs();
		printPath(0);
		cout << endl;
	}

	return 0;
}
