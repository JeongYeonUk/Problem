#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX = 4000001;

int arr[MAX];
int d[MAX];
int N;
void era()
{
	for (int i = 2; i*i <= N; ++i)
	{
		if (!arr[i])
			continue;
		for (int j = i * i; j <= N; j += i)
		{
			if (!arr[j])
				continue;
			arr[j] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 2; i <= N; ++i)
		arr[i] = i;
	era();	

	int idx = 1;
	for (int i = 2; i <= N; ++i)
	{
		if (arr[i])
		{
			d[idx] = d[idx - 1] + arr[i];
			idx++;
		}
	}
	idx -= 1;
	int l = 0, r = 1, ret = 0;
	while (true)
	{
		if (r > idx)
			break;
		int x = d[r] - d[l];
		if (r== idx && x < N)
			break;
		if (x < N)
			r++;
		else if (N < x)
			l++;
		else
		{
			ret++; r++; l++;
		}
	}

	cout << ret << '\n';

	return 0;
}
