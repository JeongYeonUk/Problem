#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'
#define INF 987654321

struct Fire {
	int y, x, m, s, d;
};

int grid[51][51];
vector<Fire> fire;
vector<Fire> vec[51][51];

int N, M, K;

// ¿ß, ø¿¿ß, ø¿, ø¿æ∆∑°, æ∆∑°, øﬁæ∆∑°, øﬁ, øﬁ¿ß
const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int cal_m(vector<Fire> clone)
{
	int size = (int)clone.size();
	int candi_m = 0;
	for (int i = 0; i < size; ++i) {
		candi_m += clone[i].m;
	}
	return candi_m;
}

int cal_s(vector<Fire> clone)
{
	int size = (int)clone.size();
	int candi_s = 0;
	for (int i = 0; i < size; ++i) {
		candi_s += clone[i].s;
	}
	return candi_s;
}

bool is_d(vector<Fire> clone)
{
	int size = (int)clone.size();
	bool dir = (clone[0].d % 2 == 1 ? true : false);
	if (dir) {
		for (int i = 1; i < size; ++i) {
			if (clone[i].d % 2 == 0) return false;
		}
	}
	else {
		for (int i = 1; i < size; ++i) {
			if (clone[i].d % 2 == 1) return false;
		}
	}
	return true;
}

void spread_fire()
{
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			int size = (int)vec[y][x].size();
			if (size == 0) {
				continue;
			}
			if (size < 2) {
				fire.push_back(vec[y][x][0]);
				vec[y][x].clear();
				continue;
			}

			vector<Fire> clone = vec[y][x];
			vec[y][x].clear();

			int nm = (cal_m(clone) / 5);
			int ns = (cal_s(clone) / size);
			bool nd = (is_d(clone));

			if (nm == 0) continue;

			if (nd) {
				Fire nFire1 = { y, x, nm, ns, 0 };
				Fire nFire2 = { y, x, nm, ns, 2 };
				Fire nFire3 = { y, x, nm, ns, 4 };
				Fire nFire4 = { y, x, nm, ns, 6 };
				fire.push_back(nFire1);
				fire.push_back(nFire2);
				fire.push_back(nFire3);
				fire.push_back(nFire4);				
			}
			else {
				Fire nFire1 = { y, x, nm, ns, 1 };
				Fire nFire2 = { y, x, nm, ns, 3 };
				Fire nFire3 = { y, x, nm, ns, 5 };
				Fire nFire4 = { y, x, nm, ns, 7 };
				fire.push_back(nFire1);
				fire.push_back(nFire2);
				fire.push_back(nFire3);
				fire.push_back(nFire4);
			}
		}
	}
}

void simul()
{
	int size = (int)fire.size();
	int ny, nx;
	for (int i = 0; i < size; ++i) {
		Fire cur = fire[i];
		ny = cur.y + (dy[cur.d] * cur.s);
		nx = cur.x + (dx[cur.d] * cur.s);

		if (ny < 0) {
			int tmp = (ny * -1) % N;
			ny = N - tmp;
		}
		if (nx < 0) {
			int tmp = (nx * -1) % N;
			nx = N - tmp;
		}
		if (ny >= N) ny = ny % N;
		if (nx >= N) nx = nx % N;

		vec[ny][nx].push_back({ ny, nx, cur.m, cur.s, cur.d });
	}
	fire.clear();
	spread_fire();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < M; ++i) {
		Fire input;
		cin >> input.y >> input.x >> input.m >> input.s >> input.d;
		input.y -= 1;
		input.x -= 1;
		fire.push_back(input);
	}

	for (int i = 0; i < K; ++i) {
		simul();
	}

	int ans = 0;
	int size = (int)fire.size();
	for (int i = 0; i < size; ++i) {
		ans += fire[i].m;
	}
	cout << ans << endl;

	return 0;
}
