#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int first(int a) {
  if (a == 1) {
    return 5000000;
  }
  else if ((a < 4) && (a >= 2)) {
    return 3000000;
  }
  else if ((a < 7) && (a >= 4)) {
    return 2000000;
  }
  else if ((a < 11) && (a >= 7)) {
    return 500000;
  }
  else if ((a < 16) && (a >= 11)) {
    return 300000;
  }
  else if(22 > a && a >= 16){
    return 100000;
  }
  else {
    return 0;
  }
}

int second(int b) {
  if (b == 1) {
    return 5120000;
  }
  else if (4 > b && b >= 2) {
    return 2560000;
  }
  else if (8 > b && b >= 4) {
    return 1280000;
  }
  else if (16 > b && b >= 8) {
    return 640000;
  }
  else if(32 > b && b >= 16){
    return 320000;
  }
  else {
    return 0;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int T; cin >> T;
  for (int tc = 0; tc < T; ++tc) {

    int a, b; cin >> a >> b;
    cout << first(a) + second(b) << endl;
  }

  return 0;
}
