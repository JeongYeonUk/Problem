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

int C, R, K;
int dom[1005][1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr); cin.tie(nullptr);
	cin >> C >> R;
	cin >> K;

	if (K > C* R) {
		cout << "0\n";
		return 0;
	}

	int count = 0;
	int start[2] = { 1,0 };
	int bias = 1;
	while (1) {
		for (int i = 0; i < R; ++i) {
			start[1] += bias;
			count++;
			if (count == K) {
				cout << start[0] << ' ' << start[1] << endl;
				return 0;
			}
		}
		C--;
		for (int i = 0; i < C; ++i) {
			start[0] += bias;
			count++;
			if (count == K) {
				cout << start[0] << ' ' << start[1] << endl;
				return 0;
			}
		}
		R--;
		bias = (bias == 1) ? -1 : 1;
	}
	

	return 0;
}
