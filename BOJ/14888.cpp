#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int n;
int arr[11];
int op[4];
int minRet;
int maxRet;

void solve(int idx, int val)
{
	if (idx == n - 1)
	{
		if (minRet > val)
			minRet = val;
		if (maxRet < val)
			maxRet = val;
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (op[i] != 0)
		{
			--op[i];
			switch (i)
			{
			case 0:
				solve(idx + 1, val + arr[idx + 1]);
				break;
			case 1:
				solve(idx + 1, val - arr[idx + 1]);
				break;
			case 2:
				solve(idx + 1, val * arr[idx + 1]);
				break;
			case 3:
				solve(idx + 1, val / arr[idx + 1]);
				break;
			default:
				break;
			}
			++op[i];
		}
	}

}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 4; ++i)
	{
		scanf("%d", &op[i]);
	}

	minRet = INF;
	maxRet = -INF;

	solve(0, arr[0]);

	printf("%d\n%d\n", maxRet, minRet);

	return 0;
}
