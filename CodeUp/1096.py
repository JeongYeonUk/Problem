n = int(input())

board = [[0 for col in range(20)] for row in range(20)]

for i in range(n):
    a, b = map(int, input().split())
    board[a-1][b-1] = 1

for i in range(0, 19):
    for j in range(0, 19):
        print(board[i][j], end=' ')
    print()
