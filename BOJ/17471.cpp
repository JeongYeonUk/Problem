#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

int person[10];
vector<int> adj[10];
bool checka[10], checkb[10];
bool visita[10], visitb[10];

void goa(int idx)
{
  if (visita[idx])
    return;
  visita[idx] = true;
  for (int i = 0; i < adj[idx].size(); ++i)
  {
    int y = adj[idx][i];
    if (checka[y] && !visita[y])
      goa(y);
  }
  return;
}

void gob(int idx)
{
  if (visitb[idx])
    return;
  visitb[idx] = true;
  for (int i = 0; i < adj[idx].size(); ++i)
  {
    int y = adj[idx][i];
    if (checkb[y] && !visitb[y])
      gob(y);
  }
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n; cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> person[i];

  for (int i = 0; i < n; ++i)
  {
    int num; cin >> num;
    for (int j = 0; j < num; ++j)
    {
      int x; cin >> x;
      adj[i].push_back(x - 1);
    }
  }

  int ans = -1;
  for (int i = 1; i < (1 << n) - 1; ++i)
  {
    vector<int> a, b;
    memset(checka, false, sizeof(checka));
    memset(checkb, false, sizeof(checkb));
    memset(visita, false, sizeof(visita));
    memset(visitb, false, sizeof(visitb));
    int suma = 0, sumb = 0;
    for (int j = 0; j < n; ++j)
    {
      if (i & (1 << j))
      {
        a.push_back(j);
        suma += person[j];
        checka[j] = true;
      }
      else
      {
        b.push_back(j);
        sumb += person[j];
        checkb[j] = true;
      }
    }

    goa(a[0]);
    bool ok = true;
    for (int j = 0; j < a.size(); ++j)
    {
      if (!visita[a[j]])
      {
        ok = false;
        break;
      }
    }
    if (!ok)
      continue;

    gob(b[0]);
    for (int j = 0; j < b.size(); ++j)
    {
      if (!visitb[b[j]])
      {
        ok = false;
        break;
      }
    }
    if (!ok)
      continue;

    int diff = abs(suma - sumb);
    if (ans == -1 || ans > diff)
      ans = diff;
  }
  cout << ans << endl;
  return 0;
}
