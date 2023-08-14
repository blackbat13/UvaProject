case_count = int(input())

for case_id in range(1, case_count + 1):
    mango_count, max_eat = map(int, input().split())
    can_eat = True
    mangos = list(map(int, input().split()))
    mango_sum = sum(mangos)
    mangos_eat = list(map(int, input().split()))

    for current_mango, current_eat in zip(mangos, mangos_eat):
        if current_eat < current_mango:
            can_eat = False

    if mango_sum > max_eat:
        can_eat = False

    if can_eat:
        print(f"Case {case_id}: Yes")
    else:
        print(f"Case {case_id}: No")
