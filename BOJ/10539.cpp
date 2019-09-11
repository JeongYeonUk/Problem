#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

ll A[101];
ll B[101];
int N;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> B[i];
    B[i] *= (ll)i;
  }

  A[1] = B[1];
  for (int i = 2; i <= N; ++i) {
    ll sum = 0;
    for (int j = 1; j < i; ++j) {
      sum += A[j];
    }
    A[i] = B[i] - sum;
  }

  for (int i = 1; i <= N; ++i) {
    cout << A[i] << ' ';
  }

  return 0;
}
