if __name__ == '__main__':
    a = int(input())
    li = ['a', 'a', 'b', 'b']
    for i in range(1,a + 1):
        print(li[(i - 1) % 4],end = '')
        