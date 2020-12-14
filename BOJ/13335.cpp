#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

#define endl '\n'
#define INF 987654321

int truck[1001];
int N, W, L;

int solve()
{
	deque<pair<int, int>> dq;
	int time;
	int weight = 0;
	int idx = 0;
	int cnt = N;
	for (time = 1; ; ++time) {
		int size = (int)dq.size();
		for (int i = 0; i < size; ++i) {
			dq[i].second++;
		}
		if (!dq.empty()) {
			pair<int,int> tmp = dq.front();
			if (tmp.second == W) {
				weight -= tmp.first;
				dq.pop_front();
				--cnt;
			}
		}
		size = (int)dq.size();
		if (cnt == 0) break;
		if (size >= W) continue;
		if (idx == N) continue;
		if (weight + truck[idx] > L) continue;

		weight += truck[idx];
		dq.push_back({ truck[idx++], 0 });
	}
	return time;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> W >> L;
	for (int i = 0; i < N; ++i) {
		cin >> truck[i];
	}

	int ans = solve();
	cout << ans << endl;

	return 0;
}
