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

int arr[5];

bool func(int a, int b) {
	if (arr[a] > arr[b]) {
		swap(arr[a], arr[b]);
		return true;
	}
	return false;
}

bool check() {
	int clone[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; ++i) {
		if (arr[i] != clone[i]) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	for (int i = 0; i < 5; ++i) {
		cin >> arr[i];
	}

	while (true) {

		if (check()) break;

		for (int i = 0; i < 4; ++i) {
			if (func(i, i + 1)) {
				for (int j = 0; j < 5; ++j) {
					cout << arr[j] << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}
