#include <iostream>

using namespace std;

int rowSize, colSize;
char board[2000][2001];
int check[2000][2000];

int nName;
char name[4000];

int q[2000][2];
int front;
int rear;

int drow[2] = { 1,0 };
int dcol[2] = { 0,1 };

void inputInit() {
    cin >> rowSize >> colSize;
    for (int i = 0; i < rowSize; i++) {
        cin >> board[i];
    }

    nName = rowSize + colSize - 1;
    for (int i = 0; i < nName; i++) {
        name[i] = 'z';
    }
}

void naming() {
    front = -1;
    rear = -1;

    check[0][0] = 1;
    rear = (rear + 1) % 2000;
    q[rear][0] = 0;
    q[rear][1] = 0;
    name[0] = board[0][0];

    while (front != rear) {
        front = (front + 1) % 2000;
        int row = q[front][0];
        int col = q[front][1];
        int index = check[row][col] - 1;

        if (name[index] < board[row][col]) continue;
        for (int k = 0; k < 2; k++) {
            int nrow = row + drow[k];
            int ncol = col + dcol[k];
            int nIndex = check[row][col];
            if (nrow >= rowSize || ncol >= colSize) continue;
            if (check[nrow][ncol]) continue;
            if (name[nIndex] < board[nrow][ncol]) continue;
            name[nIndex] = board[nrow][ncol];
            check[nrow][ncol] = check[row][col] + 1;
            rear = (rear + 1) % 2000;
            q[rear][0] = nrow;
            q[rear][1] = ncol;
        }
    }
}

void clear() {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            check[i][j] = 0;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        inputInit();
        naming();
        cout << '#' << tc << ' ';
        for (int i = 0; i < nName; i++) {
            cout << name[i];
        }
        cout << '\n';

        clear();
    }

    return 0;
}