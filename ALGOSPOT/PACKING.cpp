#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

inline int MAX(int a, int b)
{
  return a > b ? a : b;
}

inline int MIN(int a, int b)
{
  return a > b ? b : a;
}

typedef struct _tagItems
{
  string name;
  int volume;
  int needs;
}ITEM;

int N;
ITEM items[101];
int cache[1001][101];

int pack(int capacity, int item)
{
  if (item == N) return 0;
  int& ret = cache[capacity][item];
  if (ret != -1) return ret;
  ret = pack(capacity, item+1);
  if (capacity >= items[item].volume)
  {
    ret = MAX(ret, pack(capacity - items[item].volume, item + 1)
      + items[item].needs);
  }
  return ret;
}

void recon(int capacity, int item, vector<string>& pick)
{
  if (item == N) return;
  if (pack(capacity, item + 1) == pack(capacity, item))
    recon(capacity, item + 1, pick);
  else
  {
    pick.push_back(items[item].name);
    recon(capacity - items[item].volume, item + 1, pick);
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int T; cin >> T;
  for (int cases = 0; cases < T; ++cases)
  {
    int W;
    cin >> N >> W;
    for (int i = 0; i < N; ++i)
    {
      cin >> items[i].name >> items[i].volume >> items[i].needs;
    }
    memset(cache, -1, sizeof(cache));
    int sum =  pack(W, 0);
    vector<string> pick;
    recon(W, 0, pick);
    cout << sum << ' ' << pick.size() << '\n';
    for (auto a : pick)
    {
      cout << a << '\n';
    }
  }

  return 0;
}
