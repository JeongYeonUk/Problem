def solution(n):
    answer = ""

    for i in range(n):
        if i % 2 == 0:
            answer += "수"
        else:
            answer += "박"

    return answer


def solution2(n):
    s = "수박" * n
    return s[:n]
