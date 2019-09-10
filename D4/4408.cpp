#pragma warning (disable:4996)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
#define ll long long

const int INF = 987654321;
int N;
int room[201];
int ans;
int main()
{
	freopen("input.txt", "r", stdin);

	int T; cin >> T;
	for (int cases = 1; cases <= T; ++cases)
	{
		cin >> N;
		ans = 0;
		memset(room, 0, sizeof(room));
		for (int i = 0; i < N; ++i)
		{
			int a, b;
			cin >> a >> b;
			if (a > b) swap(a, b);

			if (a & 1) 
				a++;
			a >>= 1;
			if (b & 1) 
				b++;
			b >>= 1;

			for (int i = a; i <= b; ++i)
				room[i]++;
		}
		for (int i = 1; i <= 200; ++i)
		{
			if (ans < room[i])
				ans = room[i];
		}
		cout << '#' << cases << ' ' << ans << endl;
	}
	return 0;
}
