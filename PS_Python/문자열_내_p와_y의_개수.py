def solution(s):
    answer = True

    p = s.count("p") + s.count("P")
    y = s.count("y") + s.count("Y")

    return True if p == y else False


def solution2(s):
    return s.lower().count("p") == s.lower().count("y")

