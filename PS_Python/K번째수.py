import collections
import itertools


def solution(array, commands):
    answer = []

    for command in commands:
        i, j, k = command[0], command[1], command[2]
        candi = array[i - 1 : j]
        candi.sort()
        answer.append(candi[k - 1])

    return answer


def solution2(array, commands):
    return list(map(lambda x: sorted(array[x[0] - 1 : x[1]])[x[2] - 1], commands))


answer = solution2([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]])
print(answer)
