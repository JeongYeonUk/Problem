#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int INF = 987654321;
int a[101][101];
long long MAX;
int N, M;

ll sum(int sx, int sy, int ex, int ey)
{
	ll ret = 0;
	for (int i = sy; i <= ey; ++i)
	{
		for (int j = sx; j <= ex; ++j)
		{
			ret += a[i][j];
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char tmp;
			cin >> tmp;
			a[i][j] = tmp - '0';
		}
	}

	for (int i = 0; i < M - 2; ++i)
	{
		for (int j = i + 1; j < M - 1; ++j)
		{
			ll a = sum(0, 0, i, N - 1);
			ll b = sum(i + 1, 0, j, N - 1);
			ll c = sum(j + 1, 0, M - 1, N - 1);
			if (MAX < a * b * c)
				MAX = a * b * c;
		}
	}
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = i + 1; j < N - 1; ++j)
		{
			ll a = sum(0, 0, M - 1, i);
			ll b = sum(0, i + 1, M - 1, j);
			ll c = sum(0, j + 1, M - 1, N - 1);
			if (MAX < a * b * c)
				MAX = a * b * c;
		}
	}
	for (int i = 0; i < M -1; ++i)
	{
		for (int j = 0; j < N - 1; ++j)
		{
			ll a = sum(0, 0, i, N - 1);
			ll b = sum(i + 1, 0, M-1, j);
			ll c = sum(i+1,j+1,M-1,N-1);
			if (MAX < a * b * c)
				MAX = a * b * c;
		}
	}
	for (int i = M-1; i > 0; --i)
	{
		for (int j = 0; j < N - 1; ++j)
		{
			ll a = sum(i,0,M-1,N-1);
			ll b = sum(0,0,i-1,j);
			ll c = sum(0,j+1,i-1,N-1);
			if (MAX < a * b * c)
				MAX = a * b * c;
		}
	}
	for (int i = 0; i <N-1; ++i)
	{
		for (int j = 0; j < M - 1; ++j)
		{
			ll a = sum(0,0,M-1,i);
			ll b = sum(0,i+1,j,N-1);
			ll c = sum(j + 1, i+1, M - 1, N - 1);
			if (MAX < a * b * c)
				MAX = a * b * c;
		}
	}
	for (int i = N-1; i > 0; --i)
	{
		for (int j = 0; j < M - 1; ++j)
		{
			ll a = sum(0, i, M-1,N - 1);
			ll b = sum(0, 0, j, i - 1);
			ll c = sum(j + 1, 0, M - 1, i - 1);
			if (MAX < a * b * c)
				MAX = a * b * c;
		}
	}
	cout << MAX << '\n';
	return 0;
}
