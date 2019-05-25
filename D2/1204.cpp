#include <iostream>
#include <algorithm>
using namespace std;

int score[1000];
int num[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  for (int k = 0; k < T; ++k)
  {
    fill(num, num + 1000, 0);
    int number; cin >> number;
    for (int i = 0; i < 1000; ++i)
    {
      cin >> score[i];
      num[score[i]]++;
    }
    int index = 0;
    int max = 0;
    for (int i = 0; i < 1000; ++i)
    {
      if (max <= num[i])
      {
        max = num[i];
        index = i;
      }
    }
    cout << "#" << number << " " << index << '\n';
  }
  return 0;
}
