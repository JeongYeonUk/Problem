#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;

char input[101];
int N;

void toCamel() {
  char output[101] = { 0, };
  int output_index = -1;
  if (N == 1) {
    cout << input << endl;
  }
  else {
    bool flag = false;
    for (int input_index = 0; input[input_index] != NULL; input_index++) {
      if (input_index == 0) {
        if (input[input_index] - 'A' >= 0 && input[input_index] - 'A' < 26) {
          output[++output_index] = char(input[input_index] + 32);
        }
        else {
          output[++output_index] = input[input_index];
        }
      }
      else if (input[input_index] == '_') {
        flag = true;
        continue;
      }
      else if(flag){
        output[++output_index] = char(input[input_index] - 32);
        flag = false;
      }
      else {
        output[++output_index] = input[input_index];
      }
    }
    cout << output << endl;
  }
}

void toSnake() {
  char output[101] = { 0, };
  int output_index = -1;
  if (N == 2) {
    cout << input << endl;
  }
  else {
    bool flag = false;
    for (int input_index = 0; input[input_index] != NULL; input_index++) {
      if (input_index == 0) {
        if (input[input_index] - 'A' >= 0 && input[input_index] - 'A' < 26) {
          output[++output_index] = char(input[input_index] + 32);
        }
        else {
          output[++output_index] = input[input_index];
        }
      }
      else if (flag) {
        output[++output_index] = char(input[input_index] + 32);
        flag = false;
      }
      else if (input[input_index] - 'A' >= 0 && input[input_index] - 'A' < 26) {
        flag = true;
        output[++output_index] = '_';
        input_index--;
      }
      else {
        output[++output_index] = input[input_index];
      }
    }
    cout << output << endl;
  }  
}

void toPascal() {
  char output[101] = { 0, };
  int output_index = -1;
  if (N == 3) {
    cout << input << endl;
  }
  else {
    bool flag = false;
    for (int input_index = 0; input[input_index] != NULL; input_index++) {
      if (input_index == 0) {
        if (input[input_index] - 'A' >= 0 && input[input_index] - 'A' < 26) {
          output[++output_index] = input[input_index];
        }
        else {
          output[++output_index] = char(input[input_index] - 32);
        }
      }
      else if (input[input_index] == '_') {
        flag = true;
        continue;
      }
      else if (flag) {
        if (input[input_index] - 'A' >= 0 && input[input_index] - 'A' < 26) {
          output[++output_index] = input[input_index];
          flag = false;
        }
        else {
          output[++output_index] = char(input[input_index] - 32);
          flag = false;
        }
      }
      else {
        output[++output_index] = input[input_index];
      }
    }
    cout << output << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> input;

  toCamel();
  toSnake();
  toPascal();

  return 0;
}
