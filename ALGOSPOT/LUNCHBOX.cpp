#include <iostream>
#include <cstring>
using namespace std;

inline int MAX(int a, int b)
{
	return a > b ? a : b;
}

inline int MIN(int a, int b)
{
	return a > b ? b : a;
}


typedef struct _node
{
	int heat;
	int eat;
}Node;

Node rice[10001];
Node temp[10001];

void merge(int start, int mid, int end)
{
	int i = start, j = mid+1, k = start;
	while (i <= mid && j <= end)
	{
		if (rice[i].eat > rice[j].eat)
			temp[k++] = rice[i++];
		else
			temp[k++] = rice[j++];
	}
	while (i <= mid) temp[k++] = rice[i++];
	while (j <= end) temp[k++] = rice[j++];
	for (int i = start; i <= end; ++i)
	{
		rice[i] = temp[i];
	}
}

void mergeSort(int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, mid, end);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> rice[i].heat;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> rice[i].eat;
		}
		mergeSort(0, n - 1);
		int ans = 0, beginEat = 0;
		for (int i = 0; i < n; ++i)
		{			
			beginEat += rice[i].heat;
			ans = MAX(ans, beginEat + rice[i].eat);
		}
		cout << ans << '\n';
	}

	return 0;
}
