h, w = map(int, input().split())

board = [[0 for x in range(w)] for y in range(h)]

n = int(input())

dy = [0, 1]
dx = [1, 0]

for i in range(n):
    l, d, y, x = map(int, input().split())
    y -= 1
    x -= 1
    board[y][x] = 1
    ny = y + dy[d]
    nx = x + dx[d]
    for j in range(l - 1):
        board[ny][nx] = 1
        ny += dy[d]
        nx += dx[d]

for hh in range(h):
    for ww in range(w):
        print(board[hh][ww], end=' ')
    print()
