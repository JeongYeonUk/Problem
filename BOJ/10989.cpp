#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 10001;

int arr[MAX];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x; scanf("%d", &x);
		arr[x]++;
	}

	for (int i = 1; i < MAX; ++i)
	{
		while (arr[i])
		{
			printf("%d\n", i);
			arr[i]--;
		}
	}

	return 0;
}
