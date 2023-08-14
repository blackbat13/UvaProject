counters = dict()
n = int(input())

for _ in range(n):
    country = input().split(" ")[0]

    if country in counters:
        counters[country] += 1
    else:
        counters[country] = 1

for country in sorted(counters):
    print(f"{country} {counters[country]}")
