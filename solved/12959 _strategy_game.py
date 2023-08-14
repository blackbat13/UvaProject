while True:
    try:
        players, rounds = map(int, input().split())
        all_points = list(map(int, input().split()))
    except EOFError:
        break

    players_points = [0] * players
    index = 0

    for _ in range(rounds):
        for i in range(players):
            players_points[i] += all_points[index]
            index += 1

    mx = players_points[-1]
    mx_index = players - 1
    for i in range(players - 1, -1, -1):
        if players_points[i] > mx:
            mx = players_points[i]
            mx_index = i

    print(mx_index + 1)
