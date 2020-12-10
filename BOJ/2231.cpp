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

int N;
bool is_solve;

int solve(int val, int divide, int sum) {

	if (val == 0) {
		if (sum == N) {
			is_solve = true;
			return sum;
		}
		return INF;
	}

	return solve(val / divide, divide, sum + (val % divide));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N;

	is_solve = false;

	//int test = solve(198, 10, 198);

	int ans = 0;
	for (int i = 1; i < N; ++i) {
		if (is_solve) break;
		int candi = solve(i, 10, i);
		if (candi == N)
			ans = i;
	}

	cout << ans << endl;

	return 0;
}
