#pragma warning (disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 987654321;
int n, b, ret;

int main()
{
	freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases)
	{
		int arr[20] = { 0, };
		bool check[200001] = { false, };
		scanf("%d %d", &n, &b);
		int max = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
			for (int j = max; j >= 0; --j)
			{
				if (check[j])
				{
					check[j + arr[i]] = true;
				}
			}
			max += arr[i];
			check[arr[i]] = true;
		}
		int i;
		for (i = b; i <= max; ++i)
		{
			if (check[i])
				break;
		}
		printf("#%d %d\n", cases, i - b);
	}

	return 0;
}
