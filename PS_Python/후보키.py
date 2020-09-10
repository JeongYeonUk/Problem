from itertools import combinations


def solution(relation):
    answer = 0
    col_cnt = len(relation[0])
    lst = list(range(0, col_cnt))
    c_lst = []
    final = []

    for i in range(1, col_cnt+1):
        c_lst.extend(combinations(lst, i))

    # 유일성
    for col in c_lst:
        final_tmp = []
        for row in range(0, len(relation)):
            tmp_lst = []
            for c in col:
                tmp_lst.append(relation[row][c])
            final_tmp.append(tuple(tmp_lst))
        if(len(set(final_tmp)) == len(relation)):
            final.append(col)

    # 최소성
    final_set = set(final)
    for i in range(0, len(final) - 1):
        for j in range(i + 1, len(final)):
            if set(final[i]) == set(final[i]) & set(final[j]):
                final_set.discard(final[j])

    return len(final_set)


print(solution([["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"], [
      "400", "con", "computer", "4"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]]))
