if __name__ == '__main__':
    a, b = map(int, input().split())
    if(a != b):
        print(2)
    else:
        if(a % 2):
            print(a)
        else:
            print(2)
