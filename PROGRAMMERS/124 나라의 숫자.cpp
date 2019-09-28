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

string solution(int n) {
  string answer = "";
  int arr[] = { 4,1,2 };
  while (n) {
    int re = n % 3;
    n /= 3;
    if (re == 0) {
      n -= 1;
    }
    answer = to_string(arr[re]) + answer;
  }
  
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution(10) << endl;

  return 0;
}
