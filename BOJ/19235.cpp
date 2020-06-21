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

const int MAX = 10;

int N;
int result;
int g[6][4];
int b[4][6];

void gOne(int x)
{
	int idx = 0;
	for (int y = 0; y < 6; ++y) {
		if (g[y][x]) {
			idx = y;
			break;
		}
	}
	if (idx == 0) {
		g[5][x] = 1;
		return;
	}
	g[idx - 1][x] = 1;
}
void bOne(int y)
{
	int idx = 0;
	for (int x = 0; x < 6; ++x) {
		if (b[y][x]) {
			idx = x;
			break;
		}
	}
	if (idx == 0) {
		b[y][5] = 1;
		return;
	}
	b[y][idx - 1] = 1;
}

void gTwo(int x)
{
	int idx = 0;
	for (int y = 0; y < 6; ++y) {
		if (g[y][x] || g[y][x + 1]) {
			idx = y;
			break;
		}
	}
	if (idx == 0) {
		g[5][x] = 2;
		g[5][x + 1] = 2;
		return;
	}
	g[idx - 1][x] = 2;
	g[idx - 1][x + 1] = 2;
}
void bTwo(int y)
{
	int idx = 0;
	for (int x = 0; x < 6; ++x) {
		if (b[y][x]) {
			idx = x;
			break;
		}
	}
	if (idx == 0) {
		b[y][5] = 2;
		b[y][4] = 2;
		return;
	}
	b[y][idx - 1] = 2;
	b[y][idx - 2] = 2;
}

void gThree(int x)
{
	int idx = 0;
	for (int y = 0; y < 6; ++y) {
		if (g[y][x]) {
			idx = y;
			break;
		}
	}
	if (idx == 0) {
		g[5][x] = 3;
		g[4][x] = 3;
		return;
	}
	g[idx - 1][x] = 3;
	g[idx - 2][x] = 3;
}
void bThree(int y)
{
	int idx = 0;
	for (int x = 0; x < 6; ++x) {
		if (b[y][x] || b[y + 1][x]) {
			idx = x;
			break;
		}
	}
	if (idx == 0) {
		b[y][5] = 3;
		b[y + 1][5] = 3;
		return;
	}
	b[y][idx - 1] = 3;
	b[y + 1][idx - 1] = 3;
}

void simulG()
{
	bool flag = false;
	for (int y = 2; y < 6; ++y) {
		bool isClear = true;

		// 꽉찬 행이 있는지 확인
		for (int x = 0; x < 4; ++x) {
			if (g[y][x] == 0) {
				isClear = false;
				break;
			}
		}

		// 없다면 다음으로
		if (isClear == false) continue;

		// 답 +1
		result++;

		// 꽉찬 행 삭제
		for (int x = 0; x < 4; ++x) {
			g[y][x] = 0;
		}

		flag = true;
	}

	// 삭제 하지 않았다면 블럭을 옮길 필요가 없다.
	if (flag == false) return;

	int idx = 0;

	// 밑에서 2번째 행 부터 시작
	for (int y = 4; y >= 0; --y) {
		for (int x = 0; x < 4; ++x) {
			idx = 0;

			// 'ㅡ' 형태 일때
			if (g[y][x] == 2) {
				for (int yy = y + 1; yy < 6; ++yy) {
					if (g[yy][x] || g[yy][x + 1]) {
						idx = yy;
						break;
					}
				}

				// 가장 아래로 내리기
				if (idx == 0) {
					g[5][x] = 2;
					g[5][x + 1] = 2;
					g[y][x] = 0;
					g[y][x + 1] = 0;

					x++;
					continue;
				}

				// 바로 아래에 블럭이 있다면
				if (idx - 1 == y) {
					x++;
					continue;
				}

				g[idx - 1][x] = 2;
				g[idx - 1][x + 1] = 2;
				g[y][x] = 0;
				g[y][x + 1] = 0;

				x++;

				continue;
			}

			// 이외의 형태는 그냥 내려주면 된다.
			for (int yy = y + 1; yy < 6; ++yy) {
				if (g[yy][x]) {
					idx = yy;
					break;
				}
			}

			if (idx == 0) {
				g[5][x] = g[y][x];
				g[y][x] = 0;

				continue;
			}

			if (idx - 1 == y) continue;

			g[idx - 1][x] = g[y][x];
			g[y][x] = 0;
		}
	}

	simulG();
}
void simulB()
{
	bool flag = false;
	for (int x = 2; x < 6; ++x) {
		bool isClear = true;
		for (int y = 0; y < 4; ++y) {
			if (b[y][x] == 0) {
				isClear = false;
				break;
			}
		}

		if (isClear == false) continue;
		result++;

		for (int y = 0; y < 4; ++y) {
			b[y][x] = 0;
		}
		flag = true;
	}

	if (flag == false) return;

	int idx = 0;

	for (int x = 4; x >= 0; --x) {
		for (int y = 0; y < 4; ++y) {
			idx = 0;

			if (b[y][x] == 3) {
				for (int xx = x + 1; xx < 6; ++xx) {
					if (b[y][xx] || b[y + 1][xx]) {
						idx = xx;
						break;
					}
				}
				
				if (idx == 0) {
					b[y][5] = 3;
					b[y + 1][5] = 3;
					b[y][x] = 0;
					b[y + 1][x] = 0;

					y++;

					continue;
				}

				if (idx - 1 == x) {
					y++;

					continue;
				}

				b[y][idx - 1] = 3;
				b[y + 1][idx - 1] = 3;
				b[y][x] = 0;
				b[y + 1][x] = 0;

				y++;
				
				continue;
			}

			for (int xx = x + 1; xx < 6; ++xx) {
				if (b[y][xx]) {
					idx = xx;
					break;
				}
			}

			if (idx == 0) {
				b[y][5] = b[y][x];
				b[y][x] = 0;

				continue;
			}

			if (idx - 1 == x) continue;

			b[y][idx - 1] = b[y][x];
			b[y][x] = 0;
		}
	}

	simulB();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> N;

	for (int n = 0; n < N; ++n) {
		int t, y, x; cin >> t >> y >> x;

		int idx = 0;

		switch (t)
		{
		case 1:
			gOne(x);
			bOne(y);
			break;
		case 2:
			gTwo(x);
			bTwo(y);
			break;
		case 3:
			gThree(x);
			bThree(y);
			break;
		default:
			break;
		}

		simulG();

		int sg = 0;
		for (int yy = 0; yy < 2; ++yy) {
			for (int xx = 0; xx < 4; ++xx) {
				if (g[yy][xx]) {
					sg++;
					break;
				}
			}
		}

		for (int i = 0; i < sg; ++i) {
			for (int xx = 0; xx < 4; ++xx) {
				g[5][xx] = 0;
			}
			for (int xx = 0; xx < 4; ++xx) {
				for (int yy = 5; yy > 0; --yy) {
					g[yy][xx] = g[yy - 1][xx];
				}
				g[0][xx] = 0;
			}
		}

		simulB();

		int sb = 0;
		for (int xx = 0; xx < 2; ++xx) {
			for (int yy = 0; yy < 4; ++yy) {
				if (b[yy][xx]) {
					sb++;
					break;
				}
			}
		}

		for (int i = 0; i < sb; ++i) {
			for (int yy = 0; yy < 4; ++yy) {
				b[yy][5] = 0;
			}

			for (int yy = 0; yy < 4; ++yy) {
				for (int xx = 5; xx > 0; --xx) {
					b[yy][xx] = b[yy][xx - 1];
				}
				b[yy][0] = 0;
			}
		}
	}

	cout << result << '\n';

	int cnt = 0;
	for (int y = 2; y < 6; ++y) {
		for (int x = 0; x < 4; ++x) {
			if (g[y][x]) cnt++;
		}
	}
	for (int y = 0; y < 4; ++y) {
		for (int x = 2; x < 6; ++x) {
			if (b[y][x]) cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}
