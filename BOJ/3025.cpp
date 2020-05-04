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

	// tmp �迭 �ȿ� ���� �̵��ؾ��ϴ� ���� ��ȣ�� �־� ���´�.
	void process() {
		while (true) {
			int s = tmp[r - 1];

			// ������ ã�Ƴ��� �ڸ���
			// ���� �������ٸ�
			if (r > 1 && board[r - 1][s] != '.') {
				--r;
				continue;
			}

			
			if (r == R) break;  // �ٴ��̸� break
			if (board[r][s] == 'X') break;  // ���̸� break
			if (board[r][s] == '.') {
				tmp[r++] = s;  // ������̸� ���� ���� �����Ѵ�
			}
			else {
				// �������� ���� ������ �� �ִٸ�
				if (s > 0 && board[r][s - 1] == '.' && board[r - 1][s - 1] == '.') {
					tmp[r++] = s - 1;  // ���� ���� ��ȣ�� �ִ´�
				}

				// ���������� ���� ������ �� �ִٸ�
				else if (s + 1 < S && board[r][s + 1] == '.' && board[r - 1][s + 1] == '.') {
					tmp[r++] = s + 1;  // ������ ���� ��ȣ�� �ִ´�.
				}

				// ��������ε� ���� ������ �� ���ٸ�
				// r ���� ������ ���·� ����
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
		
	// �� ������ ��ó���� �س��´�.
	for (int i = 0; i < S; ++i) {
		INFO[i].tmp[0] = i;
		INFO[i].r = 1;
		INFO[i].process();
	}

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int s; cin >> s;
		INFO[s - 1].stone();  // ��ó���� �Ǿ����Ƿ� �ٷ� ���� ���´�.
		for (int i = 0; i < S; ++i) {
			INFO[i].process();  // ���� ���������� ���� �ٽ� ��ó���� �����Ѵ�. 
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
