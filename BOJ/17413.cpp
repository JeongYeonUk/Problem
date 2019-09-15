#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

char input[100001];
char output[100001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin.getline(input, 100001, '\n');
  
  int out_idx = -1;
  bool flag = false;

  for (int in_idx = 0; input[in_idx] != NULL; ++in_idx) {
    if (out_idx == -1 && input[in_idx] == '<') {
      flag = true;
      cout << input[in_idx];
    }
    else if (input[in_idx] == '>') {
      flag = false;
      cout << input[in_idx];
    }
    else if (flag) {
      cout << input[in_idx];
    }
    else if (out_idx != -1) {
      if (input[in_idx] == ' ') {
        for (; out_idx >= 0; --out_idx) {
          cout << output[out_idx];
        }
        cout << input[in_idx];
      }
      else if (input[in_idx] == '<') {
        flag = true;
        for (; out_idx >= 0; --out_idx) {
          cout << output[out_idx];
        }
        cout << input[in_idx];
      }
      else {
        output[++out_idx] = input[in_idx];
      }
    }
    else {
      output[++out_idx] = input[in_idx];
    }
  }

  if (out_idx != -1) {
    for (; out_idx >= 0; --out_idx) {
      cout << output[out_idx];
    }
  }

  return 0;
}
