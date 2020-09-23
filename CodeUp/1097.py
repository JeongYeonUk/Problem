board = [[0 for col in range(20)] for row in range(20)]

for y in range(19):
    tmp = list(map(int, input().split()))
    for x in range(19):
        board[y][x] = tmp[x]

n = int(input())

for i in range(n):
    y, x = map(int, input().split())
    for xx in range(19):
        board[y-1][xx] = board[y-1][xx] ^ 1
    for yy in range(19):
        board[yy][x-1] = board[yy][x-1] ^ 1


for y in range(19):
    for x in range(19):
        print(board[y][x], end=' ')
    print()
