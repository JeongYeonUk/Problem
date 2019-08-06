#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 100001;

int arr[MAX_N];
int minTree[MAX_N*4];
int maxTree[MAX_N*4];
int N, Q;

void init(int node, int left, int right)
{
	if (left == right)
	{
		minTree[node] = maxTree[node] = arr[left];
		return;
	}
	int mid = (left + right) >> 1;
	init(node * 2, left, mid);
	init(node * 2 + 1, mid + 1, right);
	minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
	maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
}

int minQuery(int node, int left, int right, int qleft, int qright)
{
	if (qright < left || right < qleft)
		return INF;
	if (qleft <= left && right <= qright)
		return minTree[node];
	int mid = (left + right) >> 1;
	return min(minQuery(node * 2, left, mid, qleft, qright)
		, minQuery(node * 2 + 1, mid + 1, right, qleft, qright));
}

int maxQuery(int node, int left, int right, int qleft, int qright)
{
	if (qright < left || right < qleft)
		return 0;
	if (qleft <= left && right <= qright)
		return maxTree[node];
	int mid = (left + right) >> 1;
	return max(maxQuery(node * 2, left, mid, qleft, qright)
		, maxQuery(node * 2 + 1, mid + 1, right, qleft, qright));

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	for (int cases = 0; cases < T; ++cases)
	{
		cin >> N >> Q;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		init(1, 0, N - 1);
		for (int i = 0; i < Q; ++i)
		{
			int a, b; cin >> a >> b;
			cout << maxQuery(1, 0, N - 1, a, b) - minQuery(1, 0, N - 1, a, b) << '\n';
		}
	}

	return 0;
}
