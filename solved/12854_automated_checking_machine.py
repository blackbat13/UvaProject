while True:
    try:
        tab1 = list(map(int, input().split()))
        tab2 = list(map(int, input().split()))
    except EOFError:
        break

    result = True
    for el1, el2 in zip(tab1, tab2):
        if el1 == el2:
            result = False

    if result:
        print("Y")
    else:
        print("N")
