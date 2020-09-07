def solution(skill, skill_trees):
    answer = 0

    words = [0] * 26
    for s in skill:
        words[ord(s) - ord('A')] += 1

    for skill_tree in skill_trees:
        skill_idx = 0
        tree_idx = 0
        flag = True

        while True:
            if skill_idx >= len(skill):
                break
            if tree_idx >= len(skill_tree):
                break

            if skill[skill_idx] != skill_tree[tree_idx]:
                if words[ord(skill_tree[tree_idx]) - ord('A')]:
                    flag = False
                    break
                else:
                    tree_idx += 1
            else:
                skill_idx += 1
                tree_idx += 1

        if flag:
            answer += 1

    return answer


def solution2(skill, skill_trees):
    answer = 0

    for skill_tree in skill_trees:
        skills = ''

        for tree in skill_tree:
            if tree in skill:
                skills += tree

        if skills == skill[0: len(skills)]:
            answer += 1

    return answer


print(solution2("CBD", ["BACDE", "CBADF", "AECB", "BDA"]))
