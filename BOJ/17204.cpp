#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int arr[150];
bool visit[150];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K; cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	
	int cnt = 1;
	bool flag = true;
	int cur = 0;
	while (true) {
		int next = arr[cur];
		if (next == K) {
			break;
		}
		if (visit[next]) {
			flag = false;
			break;
		}
		visit[next] = true;
		cnt++;
		cur = next;
	}
	if (!flag) {
		cout << "-1\n";
	}
	else {
		cout << cnt << endl;
	}

	return 0;
}
