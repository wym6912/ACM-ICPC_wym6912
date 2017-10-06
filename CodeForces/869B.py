'''
Created on 2017-10-6

@author: wym6912
'''

if __name__ == '__main__':
    a, b = map(int, input().split())
    ans = 1
    if b - a >= 10:
        print (0)
        exit(0)
    for i in range(a + 1, b + 1):
        ans = ans * i
    print(ans % 10)