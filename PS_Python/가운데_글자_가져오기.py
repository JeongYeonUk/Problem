def solution(s):

    s_len = len(s)
    if s_len == 1 or s_len == 2:
        return s
    answer = ""

    half_s_len = s_len // 2

    if s_len % 2 == 0:
        return s[half_s_len - 1] + s[half_s_len]
    else:
        return s[half_s_len]


print(solution("qwer"))
