#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;

struct belt
{
  int a, b,c;
};


belt b[1001];
belt arr[1010];
int N;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> b[i].a >> b[i].b >> b[i].c;
  }

  arr[1].a = b[1].a;
  arr[1].b = b[1].b;
  arr[1].c = 0;
  int tmp;

  for (int i = 2; i <= N; ++i)
  {
    tmp = arr[i - 1].b / b[i].a;
    b[i].a *= tmp; b[i].b *= tmp;
    arr[i].a = b[i].a;
    arr[i].b = b[i].b;
    if (b[i - 1].c == 0)
      arr[i].c = arr[i - 1].c;
    else
      arr[i].c = !arr[i - 1].c;
  }

  if (b[N].c == 0)
    arr[N + 1].c = arr[N].c;
  else
    arr[N + 1].c = !arr[N].c;

  cout << arr[N+1].c << ' ' << arr[N].b << '\n';

  return 0;
}
