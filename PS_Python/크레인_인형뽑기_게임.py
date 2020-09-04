def solution(board, moves):
    answer = 0

    moves = list(map(lambda x: x - 1, moves))

    column_num = len(board)

    answer_list = []
    for x in moves:
        for y in range(column_num):
            if board[y][x]:
                doll = board[y][x]
                board[y][x] = 0
                if not len(answer_list):
                    answer_list.append(doll)
                else:
                    if answer_list[-1] == doll:
                        answer_list.pop()
                        answer += 2
                    else:
                        answer_list.append(doll)
                break

    return answer


answer = solution(
    [
        [0, 0, 0, 0, 0],
        [0, 0, 1, 0, 3],
        [0, 2, 5, 0, 1],
        [4, 2, 4, 4, 2],
        [3, 5, 1, 3, 1],
    ],
    [1, 5, 3, 5, 1, 2, 1, 4],
)
print(answer)
