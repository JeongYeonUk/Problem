#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MAX_N = 12;

int prerequisite[MAX_N];
int classes[10];
int cache[10][1 << MAX_N];

int majorNum, required, semesterNum, semesterMax;

int bitCount(int n)
{
  if (n == 0) return 0;
  return n % 2 + bitCount(n / 2);
}

int graduate(int semester, int taken)
{
  if (bitCount(taken) >= required)
    return 0;

  if (semester == semesterNum)
    return INF;

  int& ret = cache[semester][taken];
  if (ret != -1) return ret;
  ret = INF;

  int canTaken = (classes[semester] & ~taken);
  for (int i = 0; i < majorNum; ++i)
  {
    if ((canTaken & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])
      canTaken &= ~(1 << i);
  }

  for (int take = canTaken; take > 0; take = ((take - 1) & canTaken))
  {
    if (bitCount(take) > semesterMax)
      continue;
    ret = min(ret, graduate(semester + 1, taken | take) + 1);
  }

  ret = min(ret, graduate(semester + 1, taken));
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int test_cases; cin >> test_cases;
  for (int cases = 0; cases < test_cases; ++cases)
  {
    memset(prerequisite, 0, sizeof(prerequisite));
    memset(classes, 0, sizeof(classes));
    memset(cache, -1, sizeof(cache));
    cin >> majorNum >> required >> semesterNum >> semesterMax;

    for (int i = 0; i < majorNum; ++i)
    {
      int preNum;
      cin >> preNum;
      for (int j = 0; j < preNum; ++j)
      {
        int subject; cin >> subject;
        prerequisite[i] |= (1 << subject);
      }
    }

    for (int i = 0; i < semesterNum; ++i)
    {
      int classNum; cin >> classNum;
      for (int j = 0; j < classNum; ++j)
      {
        int subject; cin >> subject;
        classes[i] |= (1 << subject);
      }
    }

    int result = graduate(0, 0);
    if (result == INF)
      cout << "IMPOSSIBLE" << '\n';
    else
      cout << result << '\n';
  }
  return 0;
}
