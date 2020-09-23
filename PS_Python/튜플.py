import re
from collections import Counter


def solution(s):
    s = s.lstrip('{').rstrip('}').split('},{')
    new_s = []
    for i in s:
        new_s.append(i.split(','))

    print(new_s)

    answer = []
    return answer


def solution2(s):
    s = Counter(re.findall('\d+', s))
    return list(map(int, [k for k, v in sorted(s.items(), key=lambda x: x[1], reverse=True)]))


if __name__ == "__main__":
    print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
