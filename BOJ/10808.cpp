#pragma warning(disable:4996)
#include <cstdio>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

char input[101];
int arr[26];
int main()
{
	scanf("%s", input);
	for (int i = 0; input[i] != NULL; ++i)
	{
		arr[input[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
