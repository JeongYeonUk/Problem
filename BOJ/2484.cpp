#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

inline int max(int a, int b) {
  return a > b ? a : b;
}

int arr[1000][7];
int ret[1000];
int tw[2];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 1; j <= 4; ++j) {
      int x; cin >> x;
      arr[i][x]++;
    }
  }

  bool flag;
  int maxi;
  int tw_idx;
  for (int i = 0; i < N; ++i) {
    flag = false;
    maxi = 0;
    tw_idx = -1;
    for (int j = 1; j <= 6; ++j) {
      if (arr[i][j] == 4) {
        flag = true;
        ret[i] = 50000 + j * 5000;
        break;
      }
      else if (arr[i][j] == 3) {
        flag = true;
        ret[i] = 10000 + j * 1000;
        break;
      }
      else if (arr[i][j] == 2) {
        flag = true;
        tw[++tw_idx] = j;
      }
      else if(arr[i][j] == 1){
        maxi = max(maxi, j);
      }
    }
    if (!flag) {
      ret[i] = maxi * 100;
    }
    else {
      if (tw_idx == 1) {
        ret[i] = 2000 + tw[0] * 500 + tw[1] * 500;
      }
      else if (tw_idx == 0) {
        ret[i] = 1000 + tw[0] * 100;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = max(ans, ret[i]);
  }

  cout << ans << endl;

  return 0;
}
