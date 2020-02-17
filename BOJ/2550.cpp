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
const int MAX = 10000 + 5;

int button[MAX], inButton[MAX], inBulb[MAX];
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	int N; cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> inButton[i];
	}
	for (int i = 1; i <= N; ++i) {
		cin >> inBulb[i];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (inButton[i] == inBulb[j]) {
				button[i] = j;
				break;
			}
		}
	}

	int ans = 0;
	vector<int> vec;
	vector<int> vec_ans;
	for (int i = 1; i <= N; ++i) {
		vec.clear();
		for (int j = i + 1; j <= N; ++j) {
			if (button[i] < button[j]) {
				vec.push_back(j);
			}
		}
		if (ans < vec.size()) {
			ans = (int)vec.size();
			vec_ans = vec;
		}
	}

	sort(vec_ans.begin(), vec_ans.end());

	cout << ans << endl;
	for (int i = 0; i < (int)vec_ans.size(); ++i) {
		cout << vec_ans[i] << " ";
	}
	cout << endl;

	return 0;
}
