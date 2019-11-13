#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
char a[1000000 + 3] = { '0','0' };
int main()
{
	scanf("%s", a + 2);

	int alen = strlen(a);

	for (int i = alen % 3; i < alen; i += 3)
	{
		printf("%d", (a[i] - '0') * 4 + (a[i + 1] - '0') * 2 + (a[i + 2] - '0'));
	}

	return 0;
}
