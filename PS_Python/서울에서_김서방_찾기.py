def solution(seoul):
    answer = ""

    a_idx = 0
    for idx, _ in enumerate(seoul):
        if seoul[idx] == "Kim":
            return "김서방은 " + str(idx) + "에 있다"

    return answer


def solution2(seoul):
    return "김서방은 {}에 있다".format(seoul.index("Kim"))

