import collections
import itertools


def solution(a, b):

    months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    days = ["FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"]

    day = (sum(months[: a - 1]) + (b - 1)) % 7

    answer = days[day]
    return answer

print(solution(5, 24))

