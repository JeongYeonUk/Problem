#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 5000001;

int arr[MAX];
int n, k;

void quicksort(int left, int right)
{
	int l = left, r = right, tmp;
	int p = arr[(l + r) >> 1];
	do {
		while (arr[l] < p) ++l;
		while (p < arr[r]) --r;
		if (l <= r)
		{
			tmp = arr[l]; arr[l] = arr[r]; arr[r] = tmp;
			++l; --r;
		}
	} while (l <= r);
	if (l < right)
		quicksort(l, right);
	if (left < r)
		quicksort(left, r);
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	quicksort(0, n - 1);
	printf("%d\n", arr[k - 1]);
	return 0;
}
