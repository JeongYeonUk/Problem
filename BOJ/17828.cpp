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
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	int N, X;
	cin >> N >> X;
	int A = (N * 26);
	if (N > X || A < X) {
		cout << "!" << endl; return 0;
	}

	string result(N, 'A');
	X -= N;
	for (int i = N - 1; i >= 0 && X > 0; --i) {
		int temp = min(X, 25);
		result[i] += temp;
		X -= temp;
	}

	cout << result << endl;
	
	return 0;
}
