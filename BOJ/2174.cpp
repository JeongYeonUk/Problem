#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define endl '\n'
#define INF 987654321

struct Robot {
	int y, x, dir;
};

// 오, 아래, 왼, 위
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};

Robot robot[101];
int grid[101][101];
map<char, int> pre;

// A - 가로, B - 세로
int A, B, N, M;

int move(int robo, char command)
{
	Robot cur = robot[robo];
	switch (command)
	{
	case 'L': {
		int ndir = (cur.dir + 3) % 4;
		robot[robo].dir = ndir;
		break;
	}
	case 'R': {
		int ndir = (cur.dir + 1) % 4;
		robot[robo].dir = ndir;
		break;
	}
	case 'F': {
		int ny = cur.y + dy[cur.dir];
		int nx = cur.x + dx[cur.dir];

		if (ny < 0 || nx < 0 || ny >= B || nx >= A) {
			return -1;
		}

		if (grid[ny][nx] != 0) {
			return grid[ny][nx];
		}

		grid[cur.y][cur.x] = 0;
		grid[ny][nx] = robo;

		robot[robo].y = ny; robot[robo].x = nx;
		robot[robo].dir = cur.dir;
		break;
	}
	default:
		break;
	}

	return -2;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	pre['E'] = 0;
	pre['S'] = 1;
	pre['W'] = 2;
	pre['N'] = 3;

	cin >> A >> B;
	cin >> N >> M;
	int a, b;
	char c;
	for (int i = 1; i <= N; ++i) {
		cin >> a >> b >> c;
		a -= 1; b -= 1;
		robot[i].y = b; robot[i].x = a; robot[i].dir = pre[c];
		grid[b][a] = i;
	}

	for (int i = 0; i < M; ++i) {
		cin >> a >> c >> b;
		for (int j = 0; j < b; ++j) {
			int state = move(a, c);
			switch (state)
			{
			case -1: {
				cout << "Robot " << a << " crashes into the wall" << endl;
				return 0;
			}
			case -2: break;
			default: {
				cout << "Robot " << a << " crashes into robot " << state << endl;
				return 0;
			}				
			}
		}
	}
	cout << "OK" << endl;
	return 0;
}
