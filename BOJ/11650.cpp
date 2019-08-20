#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX_N = 100001;

struct Point
{
	int x, y;
};

inline void swap(Point& a, Point& b)
{
	Point tmp = a;
	a = b;
	b = tmp;
}

Point arr[MAX_N];

void quicksort(int start, int end)
{
	int p = start;
	int i, j = start;
	if (start < end)
	{
		for (i = start + 1; i <= end; ++i)
		{
			if (arr[i].x < arr[p].x)
			{
				j++;
				swap(arr[i], arr[j]);
			}
			else if (arr[i].x == arr[p].x)
			{
				if (arr[i].y < arr[p].y)
				{
					j++;
					swap(arr[i], arr[j]);
				}
			}
		}
		swap(arr[p], arr[j]);
		p = j;
		quicksort(start, p - 1);
		quicksort(p + 1, end);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i].x >> arr[i].y;
	}

	quicksort(1, N);

	for (int i = 1; i <= N; ++i)
	{
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}

	return 0;
}
