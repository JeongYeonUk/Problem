#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
int arr[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);

	stack<int> stk;
	int ans = 1;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (stk.empty()) {
			stk.push(arr[i]);
		}
		else {
			if (stk.top() <= arr[i]) {
				stk.push(arr[i]);
			}
			else {
				if (ans < stk.size()) {
					ans = stk.size();
				}
				while (!stk.empty()) {
					stk.pop();
				}
				stk.push(arr[i]);
			}
		}
	}
	while (!stk.empty()) {
		stk.pop();
	}
	for (int i = n - 1; i >= 0; --i) {
		if (stk.empty()) {
			stk.push(arr[i]);
		}
		else {
			if (stk.top() <= arr[i]) {
				stk.push(arr[i]);
			}
			else {
				if (ans < stk.size()) {
					ans = stk.size();
				}
				while (!stk.empty()) {
					stk.pop();
				}
				stk.push(arr[i]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
