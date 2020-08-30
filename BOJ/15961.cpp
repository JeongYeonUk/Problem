#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 3000000 + 1;

int dishes[MAX << 1];
int eat[3001];

int N, D, K, C;
int answer, tmp_answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; ++i) {
		cin >> dishes[i];
		dishes[i + N] = dishes[i];
	}

	eat[C]++;
	tmp_answer = 1;
	answer = 1;

	for (int i = 0; i < (N << 1); ++i) {
		if (i >= K) {
			if (--eat[dishes[i - K]] == 0) {
				tmp_answer--;
			}
			if (eat[dishes[i]]++ == 0) {
				tmp_answer++;
				answer = max(answer, tmp_answer);
			}
		}
		else {
			if (eat[dishes[i]]++ == 0) {
				tmp_answer++;
				answer = max(answer, tmp_answer);
			}
		}
	}
	

	cout << answer << endl;

	return 0;
}
