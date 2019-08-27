#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

struct m
{
	int pos;
	int color;
};

bool cmp(m& a, m& b)
{
	if (a.color == b.color)
		return a.pos < b.pos;
	return a.color < b.color;
}

m arr[5001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i].pos >> arr[i].color;
	}

	sort(arr + 1, arr + 1 + N, cmp);

	int ret = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (i == 1)
		{
			ret += arr[i + 1].pos - arr[i].pos;
		}
		else if (i == N)
		{
			ret += arr[i].pos - arr[i - 1].pos;
		}
		else
		{
			if (arr[i].color != arr[i + 1].color)
			{
				ret += arr[i].pos - arr[i - 1].pos;
			}
			else if (arr[i].color != arr[i - 1].color)
			{
				ret += arr[i + 1].pos - arr[i].pos;
			}
			else
			{
				int first = arr[i + 1].pos - arr[i].pos;
				int second = arr[i].pos - arr[i - 1].pos;
				if (first < second)
					ret += first;
				else
					ret += second;
			}
		}
	}

	cout << ret << '\n';
	return 0;
}