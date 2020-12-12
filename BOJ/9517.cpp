#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'
#define INF 987654321

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int idx; cin >> idx;
	idx -= 1;

	int N; cin >> N;
	int time = 210;
	int a; char b;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		time -= a;
		if (time < 0) break;
		if (b == 'T') {
			idx = (idx + 1) % 8;
		}
	}
	cout << idx + 1 << endl;
	return 0;
}
