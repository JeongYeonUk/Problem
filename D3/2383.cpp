#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
using Point = pair<int, int>;

const int MAX = 11;

int map[MAX][MAX];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int  T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    int N; cin >> N;
    vector<Point> per;
    vector<Point> stair;
    for (int i = 1; i <= N; ++i)
    {
      for (int j = 1; j <= N; ++j)
      {
        cin >> map[i][j];
        if (map[i][j] == 1)
          per.push_back(make_pair(j, i));
        if (map[i][j] > 1)
          stair.push_back(make_pair(j, i));
      }
    }
    deque<int> disF;
    deque<int> disS;
    for (int i = 1; i <= per.size(); ++i)
    {
      disF.push_back(abs(per[i - 1].first - stair[0].first) + abs(per[i - 1].second - stair[0].second));
      disS.push_back(abs(per[i - 1].first - stair[1].first) + abs(per[i - 1].second - stair[1].second));
    }

    sort(disF.begin(), disF.end());
    sort(disS.begin(), disS.end());

    queue<int> S1;
    queue<int> S2;
    int time = 1;

    while (true)
    {
      while (!S1.empty())
      {
        int temp = S1.front();
        temp += temp + 1;
        if (time >= temp)
          S1.pop();
        else
          break;
      }
      while (!S2.empty())
      {
        int temp = S2.front();
        temp += temp + 1;
        if (time >= temp)
          S2.pop();
        else
          break;
      }
      if (S1.size() < 3)
      {
        for (int i = 0; i < disF.size(); ++i)
        {
          if (time >= disF[i])
          {
            if (S1.size() >= 3)
              break;
            S1.push(disF[i]);
            disF.pop_front();
            i = -1;
          }
          else
            break;
        }
      }
      if (S2.size() < 3)
      {
        for (int i = 0; i < disS.size(); ++i)
        {
          if (time >= disS[i])
          {
            if (S2.size() >= 3)
              break;
            S2.push(disS[i]);
            disS.pop_front();
            i = -1;
          }
          else
            break;
        }
      }
      time++;
    }

    cout << '#' << cases << ' ' << time << '\n';
  }
  return 0;
}
