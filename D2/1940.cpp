#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int  T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    int N; cin >> N;
    int start = 0;
    int lastSpeed = 0;
    int speed = 0;
    int flag = 0;
    for (int i = 0; i < N; ++i)
    {
      int command; cin >> command;
      if (command == 1)
      {
        cin >> speed;
        flag = 1;
      }
      else if (command == 2)
      {
        cin >> speed;
        flag = 2;
      }
      if (command != 0)
      {
        if (flag == 1)
        {
          lastSpeed += speed;
        }
        else if (flag == 2)
        {
          lastSpeed -= speed;
          if (lastSpeed < 0)
            lastSpeed = 0;
        }
        start += lastSpeed;
      }
      else
        start += lastSpeed;
    }
    cout << '#' << cases << ' ' << start << '\n';
  }

  return 0;
}
