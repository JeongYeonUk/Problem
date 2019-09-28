#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct INFO {
  int w;
  int t;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  int endPoint = (int)truck_weights.size();
  queue<INFO> non_truck;
  queue<int> end_truck;
  int curWeight = 0;
  int idx = 0;
  while (true) {
    answer++;
    if (!non_truck.empty() && answer - non_truck.front().t == bridge_length) {
      end_truck.push(non_truck.front().w);
      curWeight -= non_truck.front().w;
      non_truck.pop();
    }
    if (end_truck.size() == endPoint) {
      break;
    }
    if (idx < endPoint && curWeight + truck_weights[idx] <= weight) {
      non_truck.push({ truck_weights[idx], answer });
      curWeight += truck_weights[idx];
      idx++;
    }    
  }
  return answer;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr); cin.tie(nullptr);

  cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10}) << endl;

  return 0;
}
