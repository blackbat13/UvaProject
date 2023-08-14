values = dict()

m, n = map(int, input().split(" "))

for _ in range(m):
    word, val = input().split(" ")
    values[word] = int(val)

for _ in range(n):
    result = 0
    while True:
        text = input()
        if text == ".":
            break

        for word in text.split(" "):
            if word in values:
                result += values[word]

    print(result)
