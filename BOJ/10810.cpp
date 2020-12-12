#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'
#define INF 987654321

int bucket[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int N, M; cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		a -= 1; b -= 1;
		for (int j = a; j <= b; ++j) {
			bucket[j] = c;
		}
	}

	for (int i = 0; i < N; ++i) {
		cout << bucket[i] << " ";
	}

	return 0;
}
