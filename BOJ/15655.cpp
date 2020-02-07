#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'

int arr[10];
int out[10];
bool visit[10];
int n, m;

void solve(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= m; ++i) {
			printf("%d ", out[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (visit[i] || arr[i] < out[idx-1])
			continue;
		visit[i] = true;
		out[idx] = arr[i];
		solve(idx + 1, cnt + 1);
		visit[i] = false;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	arr[0] = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + n + 1);

	solve(1, 0);
	return 0;
}