cases_count = int(input())

for case_id in range(1, cases_count + 1):
    mobile_count = int(input())
    mobile_numbers = [input() for _ in range(mobile_count)]
    jalil_number = input()

    print(f"Case {case_id}:")

    for current_number in mobile_numbers:
        dif = 0
        for i in range(len(current_number)):
            if current_number[i] != jalil_number[i]:
                dif += 1

        if dif <= 1:
            print(current_number)
