#pragma warning (disable :4996)
#include <cstdio>
using namespace std;

int pack;
int sepe;

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	int package = 987654321, unit = 987654321;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &pack, &sepe);
		if (package > pack) package = pack;
		if (unit > sepe) unit = sepe;
	}
	int ans = 0;
	if (package < unit * 6)
		ans += package * (N / 6);
	else
		ans += unit * (N / 6) * 6;

	N %= 6;

	if (package > N * unit)
		ans += N * unit;
	else
		ans += package;

	printf("%d\n", ans);

	return 0;
}
