#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'

typedef long long ll;

const int INF = 987654321;
int N;
string arr[20001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc = 0;

    cin >> tc;
    cin >> N;


    for (int t = 1; t <= tc; t++) {
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (arr[i].size() > arr[j].size()) {
                    swap(arr[i], arr[j]);
                }
                else if (arr[i].size() == arr[j].size())
                {
                    if (arr[i] > arr[j])
                        swap(arr[i], arr[j]);
                }
            }
        }
        cout << "#" << t << endl;
        for (int i = 0; i < N; i++) {
            if (arr[i] == arr[i + 1])
                continue;
            cout << arr[i] << endl;
        }
    }
    return 0;
}