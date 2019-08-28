#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 987654321;
const int MAX = 1010;

int N,M,H, ans;
int rh[MAX][MAX], ch[MAX][MAX];
bool chk[MAX][MAX];

struct Data
{
	int r, c, h;
	bool operator<(const Data& r) const
	{
		return h > r.h;
	}
};

priority_queue<Data> pq;

void push(int r, int c, int h)
{
	if (chk[r][c]) return;
	pq.push({ r,c,h });
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> H;
	
	// input row
	for (int i = 1; i <= N + 1; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> rh[i][j];
			if (rh[i][j] == -1) rh[i][j] = H;
		}
	}

	// input col
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M+1; ++j)
		{
			cin >> ch[i][j];
			if (ch[i][j] == -1) ch[i][j] = H;
		}
	}

	// ¡á¡à¡à¡à¡à¡à¡à¡à¡à¡á
	// ¡á¡à¡à¡à¡à¡à¡à¡à¡à¡á
	// ¡á¡à¡à¡à¡à¡à¡à¡à¡à¡á
	// make
	for (int i = 1; i <= N; ++i)
	{
		push(i, 1, ch[i][1]);
		push(i, M, ch[i][M + 1]);
		chk[i][0] = chk[i][M + 1] = true;
	}

	//  ¡á¡á¡á¡á¡á¡á¡á¡á
	// ¡á¡à¡à¡à¡à¡à¡à¡à¡à¡á
	// ¡á¡à¡à¡à¡à¡à¡à¡à¡à¡á
	// ¡á¡à¡à¡à¡à¡à¡à¡à¡à¡á
	//  ¡á¡á¡á¡á¡á¡á¡á¡á
	// make
	for (int i = 1; i <= M; ++i)
	{
		push(1, i, rh[1][i]);
		push(N, i, rh[N + 1][i]);
		chk[0][i] = chk[N + 1][i] = true;
	}

	Data tmp;
	int r, c, h;
	while (!pq.empty())
	{
		tmp = pq.top(); pq.pop();
		r = tmp.r, c = tmp.c, h = tmp.h;
		if (chk[r][c]) continue;
		chk[r][c] = true;
		ans += h;
		
		// up
		// max  :  inner hole
		push(r - 1, c, max(h, rh[r][c]));

		// down
		push(r + 1, c, max(h, rh[r + 1][c]));

		// left
		push(r, c - 1, max(h, ch[r][c]));

		// right
		push(r, c + 1, max(h, ch[r][c + 1]));
	}

	cout << ans << '\n';

	return 0;
}