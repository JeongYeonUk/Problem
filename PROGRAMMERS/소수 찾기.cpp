#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool isPrime(int number)
{
  if (number == 1)
    return false;
  if (number == 2)
    return true;
  if (number % 2 == 0)
    return false;

  bool isPrime = true;
  for (int i = 2; i <= sqrt(number); ++i)
  {
    if (number % i == 0)
      return false;
  }
  return isPrime;
}

bool compare(char a, char b)
{
  return a > b;
}

int solution(string numbers) {
  int answer = 0;
  string temp = numbers;
  sort(temp.begin(), temp.end(), compare);
  vector<bool> prime(stoi(temp) + 1);

  prime[0] = false;
  for (long long i = 1; i < (int)prime.size(); ++i)
  {
    prime[i] = isPrime(i);
  }
  sort(numbers.begin(), numbers.end());
  set<int> primes;
  string sub;
  do {
    for (int i = 1; i <= (int)numbers.size(); ++i)
    {
      sub = numbers.substr(0, i);
      if (prime[stoi(sub)])
        primes.insert(stoi(sub));
    }
  } while (next_permutation(numbers.begin(), numbers.end()));
  answer = (int)primes.size();
  return answer;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution("011") << endl;

  return 0;
}
