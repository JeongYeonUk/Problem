#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int  T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    int hour1, minu1, hour2, minu2;
    cin >> hour1 >> minu1 >> hour2 >> minu2;

    int ansHour = hour1 + hour2;
    if (ansHour > 12)
      ansHour -= 12;
    int ansMinu = minu1 + minu2;
    if (ansMinu > 59)
    {
      ansHour += 1;
      ansMinu -= 60;
    }
    cout << '#' << cases << ' ' << ansHour << ' ' << ansMinu << '\n';
  }

  return 0;
}
