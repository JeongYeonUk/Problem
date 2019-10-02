#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool solution(vector<string> phone_book) {
  bool answer = true;
  sort(phone_book.begin(), phone_book.end());
  for (int i = 0; i < (int)phone_book.size() - 1; ++i)
  {
    if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
      return false;
  }
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution({ "119", "97674223", "1195524421" }) << endl;

  return 0;
}
