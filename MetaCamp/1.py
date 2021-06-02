def gcd(x, y):
    if (y == 0):
        return x
    return gcd(y, x % y)

try:
    while True:
        (n, x) = map(int, input().split())
        p = list(map(int, input().split()))
        #print(n, x)
        #print(p)
        mi = p[0]
        (ansp, ansq) = (0, 1)
        for i in range(1, n):
            #if (p[i] / mi > ansp / ansq)
            if (p[i] * ansq > ansp * mi):
                (ansp, ansq) = (p[i], mi)
            mi = min(mi, p[i])
        ansp *= x
        g = gcd(ansp, ansq)
        ansp //= g
        ansq //= g
        print("%d/%d"%(ansp, ansq))
except EOFError:
    pass