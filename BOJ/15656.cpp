#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'

int arr[10];
int visit[10];
int n, m;

void solve(int idx, int start, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; ++i) {
			printf("%d ", arr[visit[i]]);
		}
		printf("\n");
		return;
	}

	if (idx == n)
		return;

	for (int i = start; i < n; ++i) {
		visit[idx] = i;
		solve(idx + 1, i, cnt + 1);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);

	solve(0, 0, 0);
	return 0;
}