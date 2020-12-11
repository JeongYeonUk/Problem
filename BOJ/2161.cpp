#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define endl '\n'
#define X first
#define Y second
#define INF 987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int N; cin >> N;
	queue<int> card;
	for (int i = 1; i <= N; ++i) {
		card.push(i);
	}

	while (true) {
		if ((int)card.size() == 1) {
			break;
		}

		int trash = card.front(); card.pop();
		cout << trash << " ";
		int next = card.front(); card.pop();
		card.push(next);
	}
	cout << card.front();

	return 0;
}
