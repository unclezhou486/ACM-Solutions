t = int(input())
dic = {'N': 0, 'E': 1, 'S': 2, 'W': 3}
for _ in range(t):
    n = int(input())
    line = input().split()
    d1 = line[0]
    num = int(line[1])
    print(n * 2 - 1, end = ' ')
    print(d1)
    print('Z', end = ' ')
    print(num)
    for i in range(1, n):
        line = input().split()
        d2 = line[0]
        num = int(line[1])
        if (dic[d2] == (dic[d1] + 1) % 4):
            print('R')
        else:
            print('L')
        print('Z', end = ' ')
        print(num)
        d1 = d2
