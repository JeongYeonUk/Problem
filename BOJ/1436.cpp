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

	int N;
	cin >> N;

	if (N == 1) {
		cout << "666";
		return 0;
	}

	string A = "";
	int len;
	int cnt = 1;
	for (int i = 1666; ; ++i) {
		A = to_string(i);
		len = (int)A.size();

		for (int j = len - 2; j >= 1; --j) {
			if (A[j - 1] == '6' && A[j] == '6' && A[j + 1] == '6') {
				cnt++;
				if (cnt == N) {
					cout << A;
					return 0;
				}
				break;
			}
		}
	}


	return 0;
}
