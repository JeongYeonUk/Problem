#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long uint64;

int get(uint64 mask, int index)
{
  return (mask >> (index << 2)) & 15;
}

uint64 set(uint64 mask, int index, uint64 value)
{
  return mask & ~(15LL << (index << 2)) | (value << (index << 2));
}

const int INF = 0x7FFFFFFF;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  uint64 mask = 0;
  bitset<sizeof(uint64)> test = mask;
  cout << mask << '\n';
  bitset<64> setter = set(mask, 3, 5);
  setter = set(mask, 10, 3);
  cout << setter << '\n';
  cout << get(mask, 3) << '\n';
  return 0;
}
