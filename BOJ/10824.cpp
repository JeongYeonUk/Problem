#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	string A = to_string(a) + to_string(b);
	string B = to_string(c) + to_string(d);
	printf("%lld\n", stoll(A) + stoll(B));
	return 0;
}
