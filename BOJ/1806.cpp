#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int MAX = 100001;

int arr[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	int l = 0, r = 1, ret = INF;
	while (true)
	{
		if (r > N)
			break;
		int x = arr[r] - arr[l];
		if (r == N && x < M)
			break;
		if (x < M)
			r++;
		else if (M < x)
		{
			ret = min(ret, r - l);
			l++;
		}
		else
		{
			ret = min(ret, r - l);
			r++;
		}
	}
	if (ret == INF)
		cout << "0\n";
	else
		cout << ret << '\n';

	return 0;
}
