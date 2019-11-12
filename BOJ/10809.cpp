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
	memset(arr, -1, sizeof(arr));
	scanf("%s", input);
	for (int i = 0; input[i] != NULL; ++i)
	{
		if(arr[input[i] - 'a'] == -1)
			arr[input[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
