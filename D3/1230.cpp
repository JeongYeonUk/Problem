#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "r", stdin);
  for (int cases = 1; cases <= 10; ++cases)
  {
    int first; cin >> first;
    list<int> ans;
    for (int i = 0; i < first; ++i)
    {
      int val; cin >> val;
      ans.push_back(val);
    }
    int second; cin >> second;
    for (int i = 0; i < second; ++i)
    {
      auto iter = ans.begin();
      char c; cin >> c;

      if (c == 'I')
      {
        list<int> temp;
        int x, y; cin >> x >> y;
        for (int j = 0; j < y; ++j)
        {
          int val; cin >> val;
          temp.push_back(val);
        }
        for (int j = 0; j < x; ++j)
        {
          iter++;
        }
        ans.insert(iter, temp.begin(), temp.end());
      }
      else if (c == 'D')
      {
        int x, y; cin >> x >> y;
        for (int j = 0; j <= x; ++j)
        {
          iter++;
        }
        for (int j = 0; j < y; ++j)
        {
          iter = ans.erase(iter);
        }
      }
      else
      {
        int y; cin >> y;
        for (int j = 0; j < y; ++j)
        {
          int val; cin >> val;
          ans.push_back(val);
        }
      }
    }
    auto iter = ans.begin();
    cout << '#' << cases << ' ';
    for (int i = 0; i < 10; ++i)
    {
      cout << *iter << ' ';
      iter++;
    }
    cout << '\n';
  }

  return 0;
}
