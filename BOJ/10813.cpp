#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int arr[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int N, M; cin >> N >> M;
	for (int i = 0; i < N; ++i) arr[i] = i + 1;

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		swap(arr[a - 1], arr[b - 1]);
	}

	for (int i = 0; i < N; ++i) cout << arr[i] << " ";


	return 0;
}
