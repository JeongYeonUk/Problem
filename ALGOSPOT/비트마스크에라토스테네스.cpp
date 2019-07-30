#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x7FFFFFFF;
const int MAX_N = 1000000;

int n;
unsigned char sieve[(MAX_N + 7) / 8];

inline bool isPrime(int k)
{
  return sieve[k >> 3] & (1 << (k & 7));
}

inline void setComposite(int k)
{
  sieve[k >> 3] &= ~(1 << (k & 7));
}

void era()
{
  memset(sieve, 255, sizeof(sieve));
  setComposite(0);
  setComposite(1);
  int sqrtn = int(sqrt(n));
  for (int i = 2; i <= sqrtn; ++i)
  {
    if (isPrime(i))
    {
      for (int j = i * i; j <= n; j += i)
        setComposite(i);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  return 0;
}
