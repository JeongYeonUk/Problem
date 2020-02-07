#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

int arr[10];
bool visited[10];
int n, m;

void solve(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= cnt; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = arr[idx - 1]; i <= n; ++i) {
		if (visited[i])
			continue;
		visited[i] = true;
		arr[idx] = i;
		solve(idx + 1, cnt + 1);
		visited[i] = false;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	arr[0] = 1;
	solve(1, 0);

	return 0;
}