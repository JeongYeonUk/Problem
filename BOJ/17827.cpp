#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxN = 200000 + 1;

int arr[maxN];
int cache[maxN];
int N, M, V;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M >> V;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		cache[i] = arr[i];
	}
	cache[N] = arr[V - 1];
	int mod = N - V + 1;
	int m;
	int tmp;
	for (int i = 0; i < M; ++i) {
		cin >> m;
		if (m > N) {
			tmp = (m % mod);
			if (tmp < V) cout << "--" <<cache[mod + tmp] << endl;
			else cout << "--" << cache[tmp] << endl;
		}
		else {
			cout << "--" << cache[m] << endl;
		}
	}

	return 0;
}
