#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX_N = 1010;

// 별 > 동그라미 > 네모 > 세모
// 별 : 4
// 동그라미 : 3
// 네모 : 2
// 세모 : 1

int A[5], B[5];

void solve()
{
	int a4, a3, a2, a1;
	int b4, b3, b2, b1;
	a4 = A[4];	b4 = B[4];
	a3 = A[3];	b3 = B[3];
	a2 = A[2];	b2 = B[2];
	a1 = A[1];	b1 = B[1];

	if (a4 > b4)
	{
		cout << "A\n";
	}
	else if (a4 < b4)
	{
		cout << "B\n";
	}
	else if (a3 > b3)
	{
		cout << "A\n";
	}
	else if (a3 < b3)
	{
		cout << "B\n";
	}
	else if (a2 > b2)
	{
		cout << "A\n";
	}
	else if (a2 < b2)
	{
		cout << "B\n";
	}
	else if (a1 > b1)
	{
		cout << "A\n";
	}
	else if (a1 < b1)
	{
		cout << "B\n";
	}
	else
	{
		cout << "D\n";
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	
	while (N--)
	{
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		int a; cin >> a;
		for (int i = 1; i <= a; ++i)
		{
			int node; cin >> node;
			A[node]++;
		}
		int b; cin >> b;
		for (int i = 1; i <= b; ++i)
		{
			int node; cin >> node;
			B[node]++;
		}

		solve();		
	}

	return 0;
}