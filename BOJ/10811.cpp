#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define endl '\n'
#define INF 987654321

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M;

	vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		vec[i] = i + 1;
	}

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		reverse(vec.begin() + a - 1, vec.begin() + b);
	}

	for (int i = 0; i < N; ++i) {
		cout << vec[i] << " ";
	}


	return 0;
}
