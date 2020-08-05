#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1024;

int arr[MAX + 1][MAX + 1];
int N;

int get_max_two(int a, int b, int c, int d) {
	int fst = a;
	int snd = -10001;

	if (b > fst) {
		snd = fst;
		fst = b;
	}
	else {
		snd = b;
	}

	if (c > fst) {
		snd = fst;
		fst = c;
	}
	else if (c > snd) {
		snd = c;
	}

	if (d > fst) {
		snd = fst;
		fst = d;
	}
	else if (d > snd) {
		snd = d;
	}

	return snd;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> arr[y][x];
		}
	}
	int idx;
	int col;
	while (true) {
		idx = 0;
		col = 0;
		for (int y = 0; y < N; y += 2) {
			for (int x = 0; x < N; x += 2) {
				arr[idx / N][idx % N] = get_max_two(arr[y][x], arr[y][x + 1], arr[y + 1][x], arr[y + 1][x + 1]);
				idx++;
			}
			col++;
			idx = (N * col);
		}

		N >>= 1;
		if (N == 1) break;
	}

	cout << arr[0][0] << endl;

	return 0;
}
