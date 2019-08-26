#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX = 10001;

int arr[10001];
int d[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		d[i] = d[i - 1] + arr[i];
	}

	int l = 0, r = 1, ret = 0;
	while (true)
	{
		if (r > N) break;
		int x = d[r] - d[l];
		if (r == N && x < M)
			break;
		if (x < M)
			r++;
		else if (M < x)
			l++;
		else
		{
			l++; r++; ret++;
		}
	}
	cout << ret << '\n';

	return 0;
}
