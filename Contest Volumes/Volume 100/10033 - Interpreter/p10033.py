def execute(ram, register):

    pointer = 0
    steps = 0

    while (ram[pointer] != 100):
        instruction = ram[pointer] // 100
        data1 = (ram[pointer] % 100) // 10
        data2 = ram[pointer] % 10
        
        if instruction == 2:
            register[data1] = data2

        elif instruction == 3:
            register[data1] = (register[data1] + data2) % 1000

        elif instruction == 4:
            register[data1] = (register[data1] * data2) % 1000

        elif instruction == 5:
            register[data1] = register[data2]

        elif instruction == 6:
            register[data1] = (register[data1] + register[data2]) % 1000

        elif instruction == 7:
            register[data1] = (register[data1] * register[data2]) % 1000

        elif instruction == 8:
            register[data1] = ram[register[data2]]

        elif instruction == 9:
            ram[register[data2]] = register[data1]

        else:
            if register[data2]:
                pointer = register[data1] - 1

        steps += 1
        pointer += 1

    steps += 1
    print(steps)

if __name__ == '__main__':

    grpCnt = int(input())
    input()

    for grp in range(0, grpCnt):
        registry = [0] * 10
        ram = [0] * 1000

        i = 0
        while True:
            try:
                ram[i] = int(input())
                i += 1
            except (EOFError, ValueError):
                break
        if grp > 0:
            print()
        execute(ram, registry)




    """f = open('p10033.txt', 'r')
    loopCnt = int(f.readline())
    f.readline()
    for _ in range(0, loopCnt):
        registry = [0] * 10
        ram = [0] * 1000

        i = 0
        for line in f:
            if (line != "\n"):
                ram[i] = int(line)
                i += 1
            else:
                break
        execute(ram, registry, i)"""

    #f.close()
    exit(0)