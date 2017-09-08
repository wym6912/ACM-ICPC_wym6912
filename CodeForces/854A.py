def gcd(a, b):
    if(b == 0):
        return a
    else:
        return gcd(b, a % b)
    
if __name__ == '__main__':
    n = int(input())
    for i in range(n // 2, n):
        if(gcd(i, n - i) == 1 and i != n - i):
            print(min(i, n - i), max(n - i, i));
            break;
