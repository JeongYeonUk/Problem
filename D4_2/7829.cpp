#pragma warning (disable:4996)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int main()
{
	freopen("input.txt", "r", stdin);

	int T; scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases)
	{
		int p; scanf("%d", &p);
		int maxVal = 0, minVal = INF;
		for (int i = 0; i < p; ++i)
		{
			int x; scanf("%d", &x);
			if (maxVal < x)
				maxVal = x;
			if (minVal > x)
				minVal = x;
		}
		printf("#%d %d\n", cases, maxVal * minVal);
	}

	return 0;
}
