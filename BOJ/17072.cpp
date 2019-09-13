#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

struct RGB {
	int R, G, B;
};

RGB map[401][401];
int N, M;

int I(RGB rgb) {
	return 2126 * rgb.R + 7152 * rgb.G + 722 * rgb.B;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> map[y][x].R >> map[y][x].G >> map[y][x].B;
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			int inten = I(map[y][x]);
			if (0 <= inten && inten < 510000) {
				cout << '#';
			}
			else if (510000 <= inten && inten < 1020000) {
				cout << 'o';
			}
			else if (1020000 <= inten && inten < 1530000) {
				cout << '+';
			}
			else if (1530000 <= inten && inten < 2040000) {
				cout << '-';
			}
			else if (2040000 <= inten) {
				cout << '.';
			}
		}
		cout << endl;
	}

	return 0;
}
