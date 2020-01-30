#include <iostream>
using namespace std;

int num[105];
int visit[105];
bool cycle[105];
int N, cnt;

// snum과 nodenum의 값을 비교
bool solve(int snum, int nodenum) {
	if (visit[nodenum])
		return false;

	visit[nodenum] = true;
	if (snum == nodenum || solve(snum, num[nodenum])) {
		cycle[nodenum] = true;
		cnt++;
		return true;
	}
	return false;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> num[i];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			visit[j] = cycle[j];
		solve(i, num[i]);
	}

	cout << cnt << endl;
	for (int i = 1; i <= N; ++i) {
		if (cycle[i])
			cout << i << endl;
	}

	return 0;
}