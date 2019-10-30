#pragma warning (disable:4996)
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int INF = 987654321;
const int MOD = 1000000007;
char input[10000];
int len;
int cache[10000][16];

int solve(int idx, int before)
{
  if (idx == len)
    return 1;
  int& ret = cache[idx][before];
  if (ret != -1)
    return ret;
  ret = 0;
  int target = input[idx] - 'A';
  for (int i = 1; i < 16; ++i)
  {
    if ((before & i) && ((1 << target) & i))
      ret = (ret + solve(idx + 1, i)) % MOD;
  }
  return ret % MOD;

}

int main()
{
  freopen("input.txt", "r", stdin);

  int T; scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases)
  {
    memset(cache, -1, sizeof(cache));
    memset(input, 0, sizeof(input));
    len = 0;
    scanf("%s", input);
    for (int i = 0; input[i] != NULL; ++i)
    {
      len++;
    }
    printf("#%d %d\n", cases, solve(0, 1));
  }

  return 0;
}
