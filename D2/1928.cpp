#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

using MyMap = unordered_map<char, int>;
MyMap map;
void setEncoding()
{

  int value = 0;
  for (int i = 65; i < 91; ++i)
  {
    map[(char)i] = value++;
  }
  for (int i = 97; i < 123; ++i)
  {
    map[(char)i] = value++;
  }
  for (int i = 48; i < 58; ++i)
  {
    map[(char)i] = value++;
  }
  map['+'] = value++;
  map['/'] = value;
}
string changeBit(int number)
{
  string ret;
  ret.resize(6);
  int length = 5;
  int ans = 0;
  while (number != 0)
  {
    int a = number % 2;
    if (a == 1)
      ret[length] = '1';
    else
      ret[length] = '0';
    number /= 2;
    length--;
  }
  for (int i = 0; i < 6; ++i)
  {
    if (ret[i] == '\0')
      ret[i] = '0';
  }
  return ret;
}
char setDecoding(string & str)
{
  int mul = 1 << 7;
  int ans = 0;
  for (int i = 0; i < 8; ++i)
  {
    if ((str[i] - '0') == 1)
    {
      ans += mul;
    }
    mul >>= 1;
  }
  return (char)ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  setEncoding();
  int T; cin >> T;
  for (int cases = 1; cases <= T; ++cases)
  {
    string s; cin >> s;
    string bit;
    for (int i = 0; i < s.length(); ++i)
    {
      bit += changeBit(map[s[i]]);
    }
    string ans;
    for (; bit.length() != 0;)
    {
      string str(bit.begin(), bit.begin() + 8);
      ans += setDecoding(str);
      bit.erase(bit.begin(), bit.begin() + 8);
    }
    cout << '#' << cases << ' ' << ans << '\n';
  }

  return 0;
}
//#include <iostream>
//using namespace std;
//int m[128];
//void init() {
//  for (int i = 0; i < 26; i++) m['A' + i] = i;
//  for (int i = 0; i < 26; i++) m['a' + i] = 26 + i;
//  for (int i = 0; i < 11; i++) m['0' + i] = 52 + i;
//  m['+'] = 62;
//  m['/'] = 63;
//}
//void decode(char* src, char* dst) {
//  int bits, pos = 0, pos2 = 0;
//  while (src[pos]) {
//    bits = m[src[pos++]] << 18;
//    bits += m[src[pos++]] << 12;
//    bits += m[src[pos++]] << 6;
//    bits += m[src[pos++]];
//    dst[pos2++] = bits >> 16 & 0xFF;
//    dst[pos2++] = bits >> 8 & 0xFF;
//    dst[pos2++] = bits & 0xFF;
//  }
//  dst[pos2] = 0;
//}
//int main() {
//  init();
//  int T;
//  scanf("%d", &T);
//  char encoded[100000];
//  char decoded[100000];
//  for (int tc = 1; tc <= T; tc++) {
//    scanf("%s", encoded);
//    decode(encoded, decoded);
//    printf("#%d %s \n", tc, decoded);
//  }
//}
