#include <iostream>
using namespace std;

#define endl '\n'

int main(void) {
    //freopen("eval_input.txt", "r", stdin);
    int T; cin >> T;

    //const
    int sub[] = { 20, 5, 4, 2, 1 };

    for (int test_case = 1; test_case <= T; test_case++) {
        int p, q; cin >> p >> q;
        char buf[2000];
        bool sml[21][21][21]; 
        for (int i = 0; i < 21; i++) { 
            for (int j = 0; j < 21; j++) { 
                for (int k = 0; k < 21; k++) { 
                    sml[i][j][k] = true;
                }
            }
        }

        for (int q = 0; q < 21; q++) { 
            for (int w = 0; w < 21; w++) { 
                sml[0][w][q] = sml[w][q][0] = sml[w][0][q] = 0; 
            } 
        }
        int ss = 0, mm = 0, ll = 0;
        for (int pp = 0; pp < p; pp++) {
            cin >> buf;
            int c = 0;
            bool init = true; 
            int dot = 0;
            while (buf[c] != '\0') {
                if (init) {
                    if (buf[c] == '.') { 
                        dot++; 
                    }
                    else {
                        init = false;
                        for (int s = 0; s < 21; s++) {
                            for (int m = 0; m < 21; m++) {
                                for (int l = 0; l < 21; l++) {
                                    if (s * ss + m * mm + l * ll != dot) {
                                        sml[s][m][l] = false;
                                    }

                                }
                            }
                        }
                    }
                }
                if (!init) {
                    if (buf[c] == '(') ss += 1; 
                    if (buf[c] == ')') ss -= 1;
                    if (buf[c] == '{') mm += 1;
                    if (buf[c] == '}') mm -= 1;
                    if (buf[c] == '[') ll += 1;
                    if (buf[c] == ']') ll -= 1;
                }
                c++;
            }
        }
        cout << "#" << test_case << " ";
        ss = 0, mm = 0, ll = 0;
        for (int qq = 0; qq < q; qq++) {
            cin >> buf;
            int c = 0;
            bool init = true; 
            int dot = 0;
            while (buf[c] != '\0') {
                if (init) {
                    if (buf[c] == '.') { 
                        dot++;
                    }
                    else {
                        init = false;
                        int result = -1, tmp; 
                        int count = 0;
                        for (int s = 0; s < 21; s++) {
                            for (int m = 0; m < 21; m++) {
                                for (int l = 0; l < 21; l++) {
                                    if (sml[s][m][l] == true) {
                                        tmp = s * ss + m * mm + l * ll; 
                                        count++;
                                        if (count > 1 && result != tmp) { 
                                            result = -1; 
                                        }
                                        else { 
                                            result = tmp; 
                                        }
                                    }
                                }
                            }
                        }
                        cout << result << " ";
                    }
                }
                if (!init) {
                    if (buf[c] == '(') { ss += 1; }
                    if (buf[c] == ')') { ss -= 1; }
                    if (buf[c] == '{') { mm += 1; }
                    if (buf[c] == '}') { mm -= 1; }
                    if (buf[c] == '[') { ll += 1; }
                    if (buf[c] == ']') { ll -= 1; }
                }
                c++;
            }

        }
        cout << endl;
    }
    return 0;
}