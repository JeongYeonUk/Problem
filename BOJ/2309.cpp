#pragma warning(disable:4996)
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

vector<int> height;
int sum;
void solve() {
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if ((sum - height[i] - height[j]) == 100) {
				for (int k = 0; k < 9; ++k) {
					if (k != i && k != j)
						cout << height[k] << endl;					
				}
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	for (int i = 0; i < 9; ++i) {
		int x; cin >> x;
		height.push_back(x);
		sum += x;
	}

	sort(height.begin(), height.end());

	solve();

	return 0;
}
