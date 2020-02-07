#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

#define endl '\n'

int arr[10];
vector<int> ret;

void solve(int idx, int sum) {
	ret.push_back(sum);
	if (idx == 9)
		return;
	solve(idx + 1, sum + arr[idx + 1]);
}

int main()
{
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &arr[i]);
	}

	solve(0, arr[0]);
	int ans = 0;
	for (int i = 0; i < ret.size(); ++i) {
		if (abs(100 - ans) >= abs(100 - ret[i])) {
			ans = ret[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}