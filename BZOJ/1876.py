if __name__ == '__main__':
    a, b = int(input()), int(input())
    c = a % b
    while c != 0:
        a = b
        b = c
        c = a % b
    print(b)
