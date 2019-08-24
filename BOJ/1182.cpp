#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int INF = 987654321;

int arr[21];
int N, S;
int ret;

void solve(int idx, int sum)
{
  sum += arr[idx];
  if (idx >= N)
    return;
  if (sum == S)
    ret++;
  solve(idx + 1, sum - arr[idx]);
  solve(idx + 1, sum);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> S;
  for (int i = 0; i < N; ++i)
  {
    cin >> arr[i];
  }

  solve(0, 0);
  
  cout << ret << '\n';

  return 0;
}
