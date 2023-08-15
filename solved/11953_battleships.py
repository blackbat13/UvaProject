def clear(grid: list, row: int, column: int):
    if (
        not (0 <= row < len(grid))
        or not (0 <= column < len(grid[row]))
        or grid[row][column] == "."
    ):
        return

    grid[row][column] = "."
    clear(grid, row - 1, column)
    clear(grid, row + 1, column)
    clear(grid, row, column - 1)
    clear(grid, row, column + 1)


cases_count = int(input())

for case_id in range(1, cases_count + 1):
    grid_size = int(input())
    grid = [[*input()] for _ in range(grid_size)]
    result = 0

    for row in range(grid_size):
        for column in range(grid_size):
            if grid[row][column] == "x":
                result += 1
                clear(grid, row, column)

    print(f"Case {case_id}: {result}")
