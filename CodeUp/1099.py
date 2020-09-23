board = [[0 for x in range(10)] for y in range(10)]

for y in range(10):
    t = list(map(int, input().split()))
    for x in range(10):
        board[y][x] = t[x]

flag = False


def dfs(y, x, board):
    global flag
    if flag:
        return

    if board[y][x] == 2:
        board[y][x] = 9
        flag = True
        return

    dy = [0, 1]
    dx = [1, 0]

    board[y][x] = 9
    for d in range(2):
        ny = y + dy[d]
        nx = x + dx[d]

        if board[ny][nx] == 1:
            continue

        if board[ny][nx] == 0 or board[ny][nx] == 2:
            dfs(ny, nx, board)
    flag = True
    return


dfs(1, 1, board)

for y in range(10):
    for x in range(10):
        print(board[y][x], end=' ')
    print()
