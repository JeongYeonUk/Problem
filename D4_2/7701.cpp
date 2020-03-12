#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

const int INF = 987654321;

char buffer[128];
int N, maxLen, len;

int main() {
	//freopen("input.txt", "r", stdin);

	int tc; scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t) {
		scanf("%d", &N);

		set<string> table[51];
		for (int i = 0; i < N; ++i) {
			scanf("%s", buffer);
			len = strlen(buffer);
			table[len].insert(buffer);
			if (maxLen <= len)
				maxLen = len;
		}

		string temp = "";
		printf("#%d\n", t);
		for (int i = 1; i <= maxLen; ++i) {
			set<string>& cur = table[i];
			if (cur.empty())
				continue;
			for (auto& out : cur) {
				printf("%s\n", out.c_str());
			}
		}
	}


	return 0;
}