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

const int MAX = 300 + 1;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int a[MAX];
int d[MAX];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> a[i];
	}

	// 최대값을 얻는 것이므로
	// 2개의 계단까지는
	// 모든 계단을 밟는 것이 최대값
	d[1] = a[1];
	d[2] = a[1] + a[2];

	for (int i = 3; i <= N; ++i)
	{
		// 3개의 계단을 연속으로 밟지 못하므로
		d[i] = a[i] + a[i - 1] + d[i - 3];

		// 이전 계단을 밟지 않을 경우
		d[i] = max(d[i], a[i] + d[i - 2]);
	}

	cout << d[N] << endl;

	return 0;
}
