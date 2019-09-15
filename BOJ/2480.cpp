#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

inline int max(int a, int b) {
  return a > b ? a : b;
}

int arr[7];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  for (int i = 1; i <= 3; ++i) {
    int x; cin >> x;
    arr[x]++;
  }

  bool flag = false;
  int maxi = 0;
  int ret = 0;
  int val = 0;
  for (int i = 1; i <= 6; ++i) {
    if (arr[i]) {
      maxi = max(maxi, i);
    }
    if (arr[i] > 1) {
      flag = true;
      ret = i;
      val = arr[i];
    }
  }

  if (flag) {
    if (val == 3) {
      cout << 10000 + ret * 1000 << endl;
    }
    else if (val == 2) {
      cout << 1000 + ret * 100 << endl;
    }
  }
  else {
    cout << maxi * 100 << endl;
  }

  return 0;
}
