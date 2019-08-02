#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 100001;
int N,M;
int arr[MAX_N];
int minTree[MAX_N * 4];
int maxTree[MAX_N * 4];

int minInit(int node, int left, int right)
{
	if (left == right)
		return minTree[node] = arr[left];
	int mid = (left + right) >> 1;
	return minTree[node] = min(minInit(node * 2, left, mid),
		minInit(node * 2 + 1, mid + 1, right));
}

int maxInit(int node, int left, int right)
{
	if (left == right)
		return maxTree[node] = arr[left];
	int mid = (left + right) >> 1;
	return maxTree[node] = max(maxInit(node * 2, left, mid),
		maxInit(node * 2 + 1, mid + 1, right));
}

int minQuery(int node, int left, int right, int qleft, int qright)
{
	if (qright < left || right < qleft)
		return INF;
	if (qleft <= left && right <= qright)
		return minTree[node];
	int mid = (left + right) >> 1;
	return min(minQuery(node * 2, left, mid, qleft, qright),
		minQuery(node * 2 + 1, mid+1, right, qleft, qright));
}

int maxQuery(int node, int left, int right, int qleft, int qright)
{
	if (qright < left || right < qleft)
		return 0;
	if (qleft <= left && right <= qright)
		return maxTree[node];
	int mid = (left + right) >> 1;
	return max(maxQuery(node * 2, left, mid, qleft, qright),
		maxQuery(node * 2 + 1, mid+1, right, qleft, qright));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}

	minInit(1, 1, N);
	maxInit(1, 1, N);

	for (int i = 1; i <= M; ++i)
	{
		int a, b; cin >> a >> b;
		int iMax = maxQuery(1, 1, N, a, b);
		int iMin = minQuery(1, 1, N, a, b);
		cout << iMin << ' ' << iMax << '\n';
	}
	return 0;
}
