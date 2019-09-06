#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;
const int dx[] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[] = { 0,1,1,1,0,-1,-1,-1 };

struct TREE {
	int y, x, age;
	bool alive;
};

bool cmp(TREE& a, TREE& b) {
	return a.age < b.age;
}

int N, M, K;
int map[50][50], A[50][50];
vector<TREE> tree;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> A[y][x];
			map[y][x] = 5;
		}
	}
	for (int i = 0; i < M; ++i) {
		int x, y, age; cin >> x >> y >> age;
		x--; y--; tree.push_back({ y,x,age,true });
	}

	int tree_count;
	int dead_count = 0;
	for (int year = 1; year <= K; ++year) {
		tree_count = (int)tree.size();
		dead_count = 0;
		for (int season = 1; season <= 4; ++season) {
			switch (season)
			{
			case 1:
			{
				sort(tree.begin(), tree.end(), cmp);
				for (int i = 0; i < tree_count; ++i) {
					int& food = map[tree[i].y][tree[i].x];
					if (food - tree[i].age < 0) {
						tree[i].alive = false;
						tree[i].age *= -1;
						dead_count++;
					}
					else {
						food -= tree[i].age;
						tree[i].age++;
					}
				}
				break;
			}
			case 2:
			{
				sort(tree.begin(), tree.end(), cmp);
				for (int i = 0; i < tree_count; ++i) {
					if (tree[i].alive) break;
					A[tree[i].y][tree[i].x] += ((tree[i].age * -1) / 2);
				}
				reverse(tree.begin(), tree.end());
				for (int i = 0; i < dead_count; ++i)
					tree.pop_back();
				sort(tree.begin(), tree.end(), cmp);
				tree_count = (int)tree.size();
				break;
			}
			case 3:
			{
				for (int i = 0; i < tree_count; ++i) {
					if (tree[i].age % 5 == 0) {
						for (int dir = 0; dir < 8; ++dir) {
							int ny = tree[i].y + dy[dir];
							int nx = tree[i].x + dx[dir];
							if (ny < 0 || nx < 0 || ny >= N || nx >= N)
								continue;
							tree.push_back({ ny,nx,1,true });
						}
					}
				}
				break;
			}
			case 4:
			{
				for (int y = 0; y < N; ++y) {
					for (int x = 0; x < N; ++x) {
						map[y][x] += A[y][x];
					}
				}
				break;
			}
			default:
				break;
			}
		}
	}
	cout << (int)tree.size() << '\n';
	return 0;
}
