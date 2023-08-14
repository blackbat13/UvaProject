while True:
    try:
        line = input().split(" ")
    except EOFError:
        break

    passwordSize = int(line[0])
    encodedMsg = line[1]
    counters = dict()

    currentStr = encodedMsg[0:passwordSize]
    hash = 0
    powerOf26 = 1

    for i in range(passwordSize):
        hash += (ord(currentStr[i]) - ord("a") + 1) * powerOf26
        powerOf26 *= 26

    powerOf26 //= 26
    counters[hash] = 1
    currentCounter = 1
    maxCounter = 1
    password = currentStr

    for i in range(1, len(encodedMsg) - passwordSize + 1):
        hash -= ord(currentStr[0]) - ord("a") + 1
        currentStr = currentStr[1:]
        currentStr += encodedMsg[i + passwordSize - 1]
        hash //= 26
        hash += (ord(currentStr[passwordSize - 1]) - ord("a") + 1) * powerOf26
        if hash in counters:
            counters[hash] += 1
        else:
            counters[hash] = 1

        currentCounter = counters[hash]
        if currentCounter > maxCounter:
            maxCounter = currentCounter
            password = currentStr

    print(password)
