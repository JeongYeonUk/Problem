#pragma warning (disable : 4996)
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

/*
2
5 6
......
.939..
.3428.
.9393.
......
10 10
..........
.99999999.
.9.323239.
.91444449.
.91444449.
.91444449.
.91444449.
.91232329.
.99999999.
..........

3
35
*/
#define endl '\n'
#define rint register int
#define ll long long
#define INF 987654321
#define MAX 1000 + 5
#define abs(x) (x > 0 ? x : -x)
#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)

const int dy[] = { 0,0,1,-1,-1,-1,1,1 };
const int dx[] = { 1,-1,0,0,1,-1,1,-1 };

struct INFO {
	int y, x;
};

char board[MAX][MAX];
int H, W;
queue<INFO> q;

bool solve() {
	int qsize = (int)q.size();
	rint y, x;
	bool flag = false;
	for (rint i = 0; i < qsize; ++i) {
		y = q.front().y; x = q.front().x;
		q.pop();

		for (rint dir = 0; dir < 8; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W)
				continue;
			register char& temp = board[ny][nx];
			if (temp != '.') {
				temp--;
				if (temp == '0') {
					temp = '.';
					q.push({ ny,nx });
					flag = true;
				}
			}
		}
	}
	return flag;
}

int main()
{
	setbuf(stdout, NULL);
	rint tc; scanf("%d", &tc);
	for (rint t = 1; t <= tc; ++t) {
		scanf("%d %d", &H, &W);
		for (rint y = 0; y < H; ++y) {
			for (rint x = 0; x < W; ++x) {
				scanf(" %1c", &board[y][x]);
				if (board[y][x] == '.') {
					q.push({ y,x });
				}
			}
		}
		
		rint time = 0;
		while (solve()) {
			time++;
		}
		printf("#%d %d\n", t, time);
	}

	return 0;
}
