#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[101];
int cache[101];
int choices[101];
int len;
int LIS(int start)
{
  int& ret = cache[start + 1];
  if (ret != -1) return ret;
  ret = 1;
  int bestNext = -1;
  for (int next = start + 1; next < len; ++next)
  {
    if (start == -1 || arr[start] < arr[next])
    {
      int cand = LIS(next) + 1;
      if (cand > ret)
      {
        ret = cand;
        bestNext = next;
      }
    }
  }
  choices[start + 1] = bestNext;
  return ret;
}

void recon(int start, vector<int>& seq)
{
  if (start != -1) seq.push_back(arr[start]);
  int next = choices[start + 1];
  if (next != -1)
    recon(next, seq);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cout << "Length : ";
  cin >> len;
  for (int i = 0; i < len; ++i)
  {
    cin >> arr[i];
  }
  memset(cache, -1, sizeof(cache));
  memset(choices, -1, sizeof(choices));
  cout << "LIS length : ";
  cout << LIS(-1) << '\n';

  vector<int> seq;
  recon(-1, seq);

  for (auto a : seq)
    cout << a << ' ';

  return 0;
}
