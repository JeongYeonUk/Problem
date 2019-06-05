#pragma warning (disable :4996)
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct _apply
{
	int docu;
	int talk;
}Apply;

Apply arr[100000];
int N;

bool compare(Apply a, Apply b)
{
	if (a.docu < b.docu)
		return true;
	return false;
}

int main()
{
	int T; scanf("%d", &T);
	for (int cases = 0; cases < T; ++cases)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d", &arr[i].docu, &arr[i].talk);			
		}	
		sort(arr, arr + N, compare);
		int ans = 1;
		int pivot = arr[0].talk;
		for (int i = 1; i < N; ++i)
		{
			if (pivot > arr[i].talk)
			{
				ans++;
				pivot = arr[i].talk;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
