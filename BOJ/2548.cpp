#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
const int MAX = 20000 + 5;

int prefix[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int N; cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());
	
	prefix[0] = vec[0];
	for (int i = 1; i < N; ++i) {
		prefix[i] = prefix[i - 1] + vec[i];
	}

	int ans = 2e9;
	int pos = -1;

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += abs(vec[i] - vec[0]);
	}

	if (ans > sum) {
		ans = sum;
		pos = 0;
	}

	for (int k = 1; k < N; ++k) {
		int sum = 0;
		sum = k * vec[k] - prefix[k - 1] + (prefix[N - 1] - prefix[k]) - (N - 1 - k) * vec[k];

		if (ans > sum) {
			ans = sum;
			pos = k;
		}
	}

	cout << vec[pos] << endl;

	return 0;
}
