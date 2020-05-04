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

const int MAXR = 30000 + 1;
const int MAXC = 30 + 1;

int R, S, N;
char board[MAXR][MAXC];

struct _info {
	int tmp[MAXR];
	int r;

	void stone() {
		board[r - 1][tmp[r - 1]] = 'O';
	}

	// tmp 배열 안에 돌이 이동해야하는 열의 번호를 넣어 놓는다.
	void process() {
		while (true) {
			int s = tmp[r - 1];

			// 이전에 찾아놓은 자리에
			// 돌이 놓아졌다면
			if (r > 1 && board[r - 1][s] != '.') {
				--r;
				continue;
			}

			
			if (r == R) break;  // 바닥이면 break
			if (board[r][s] == 'X') break;  // 벽이면 break
			if (board[r][s] == '.') {
				tmp[r++] = s;  // 빈공간이면 같은 열을 유지한다
			}
			else {
				// 왼쪽으로 굴러 떨어질 수 있다면
				if (s > 0 && board[r][s - 1] == '.' && board[r - 1][s - 1] == '.') {
					tmp[r++] = s - 1;  // 왼쪽 열의 번호를 넣는다
				}

				// 오른쪽으로 굴러 떨어질 수 있다면
				else if (s + 1 < S && board[r][s + 1] == '.' && board[r - 1][s + 1] == '.') {
					tmp[r++] = s + 1;  // 오른쪽 열의 번호를 넣는다.
				}

				// 어느쪽으로도 굴러 떨어질 수 없다면
				// r 값을 유지한 상태로 종료
				else {
					break;
				}
			}
		}
	}

}INFO[MAXC];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> R >> S;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < S; ++c) {
			cin >> board[r][c];
		}
	}
		
	// 각 열마다 전처리를 해놓는다.
	for (int i = 0; i < S; ++i) {
		INFO[i].tmp[0] = i;
		INFO[i].r = 1;
		INFO[i].process();
	}

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int s; cin >> s;
		INFO[s - 1].stone();  // 전처리가 되었으므로 바로 돌을 놓는다.
		for (int i = 0; i < S; ++i) {
			INFO[i].process();  // 돌이 놓아졌음에 따라 다시 전처리를 수행한다. 
		}
	}

	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < S; ++c) {
			cout << board[r][c];
		}
		cout << endl;
	}

	return 0;
}
