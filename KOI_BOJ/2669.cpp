#include <iostream>
using namespace std;

int map[101][101];
int ldx[4];
int ldy[4];
int rux[4];
int ruy[4];
int main()
{
	for (int i = 0; i < 4; ++i) {
		cin >> ldx[i] >> ldy[i] >> rux[i] >> ruy[i];
	}

	for (int i = 0; i < 4; ++i) {
		for (int y = ldy[i]; y < ruy[i]; ++y) {
			for (int x = ldx[i]; x < rux[i]; ++x) {
				map[y][x] = 1;
			}
		}
	}

	int ans = 0;
	for (int y = 1; y <= 100; ++y) {
		for (int x = 1; x <= 100; ++x) {
			ans += (map[y][x] == 1 ? 1 : 0);
		}
	}
	cout << ans << endl;
	return 0;
}