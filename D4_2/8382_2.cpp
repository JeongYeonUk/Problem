#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'
#define rint register int
#define ll long long
#define INF 987654321
#define abs(x) (x > 0 ? x : -x)
#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)

int main()
{
	rint tc; scanf("%d", &tc);
	for (rint t = 1; t <= tc; ++t) {
		rint sx, sy, ex, ey, ans;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		rint x = abs((sx - ex));
		rint y = abs((sy - ey));

		ans = ((x + y) & 1) ? ((max(x, y) << 1) - 1) : (max(x, y) << 1);

		printf("#%d %d\n", t, ans);
	}

	return 0;
}
