#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 1000001;

int arr[MAX_N];
int N;

void quicksort(int start, int end)
{
	int l = start, r = end, tmp;
	int p = arr[(l + r) >> 1];
	do
	{
		while (arr[l] < p) ++l;
		while (arr[r] > p) --r;
		if (l <= r)
		{
			tmp = arr[l]; 
			arr[l] = arr[r];
			arr[r] = tmp;
			++l; --r;
		}
	} while (l <= r);
	if (l < end) quicksort(l, end);
	if (start < r) quicksort(start, r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}
	quicksort(1,N);

	for (int i = 1; i <= N; ++i)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}
