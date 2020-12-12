#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'
#define INF 987654321

struct INFO {
	int num;
	int last;
	int voted;
};

INFO pic[21];
bool is_post[101];

int N, M, cnt;

void update(int val)
{
	for (int i = 0; i < N; ++i) {
		if (pic[i].num == val) {
			pic[i].voted++;
			return;
		}
	}	
}

void add(int val, int last)
{
	if (cnt < N) {
		cnt++;
		for (int i = 0; i < N; ++i) {
			if (pic[i].num == 0) {
				pic[i] = { val, last, 0 };
				is_post[val] = true;
				break;
			}
		}
		return;
	}

	if (cnt >= N) {
		int candi_voted = pic[0].voted;
		int candi_last = pic[0].last;
		int idx = 0;
		for (int i = 1; i < N; ++i) {
			if (pic[i].voted < candi_voted) {
				candi_voted = pic[i].voted;
				candi_last = pic[i].last;
				idx = i;
				continue;
			}

			if (pic[i].voted == candi_voted) {
				if (pic[i].last < candi_last) {
					candi_last = pic[i].last;
					idx = i;
					continue;
				}
			}
		}

		is_post[pic[idx].num] = false;
		pic[idx] = { val, last, 0 };
		is_post[val] = true;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> N >> M;
	int val;
	for (int i = 0; i < M; ++i) {
		cin >> val;
		if (is_post[val]) {
			update(val);
			continue;
		}
		add(val, i);
	}

	for (int i = 1; i < 101; ++i) {
		if (is_post[i]) cout << i << " ";
	}

	return 0;
}
