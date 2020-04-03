#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define MAX 51
#define INF 987654321
#define MOD 998244353

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t[MAX], a[MAX], b[MAX];
ll ans[MAX];
int N, M;
int main() 
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	int tc; cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) 
	{
		cin >> N;
		for (int i = 2; i <= N; ++i) 
		{
			cin >> t[i] >> a[i] >> b[i];
		}
		cout << "#" << tt << " ";
		cin >> M;
		for (int i = 0; i < M; ++i) 
		{
			int num; cin >> num;
			ans[0] = 1; 
			ans[1] = num;
			for (int j = 2; j <= N; ++j)
			{
				switch (t[j])
				{
				case 1:
					ans[j] = (ans[a[j]] + ans[b[j]]) % MOD;
					break;
				case 2:
					ans[j] = (a[j] * ans[b[j]]) % MOD;
					break;
				case 3:
					ans[j] = (ans[a[j]] * ans[b[j]]) % MOD;
					break;
				default:
					break;
				}
			}
			cout << ans[N] << " ";
		}
		cout << endl;
	}

	return 0;
}
