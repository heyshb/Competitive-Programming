Cases = int(input())

def solve(a, d):
    N = len(a)
    if (N == 0):
        return ''
    zeros = [-1]
    for i in range(N):
        if (a[i] == d):
            zeros.append(i)
    zeros.append(N)
    M = len(zeros)
    ret = ''
    for i in range(1, M):
        if (zeros[i] > zeros[i - 1] + 1):
            ret += ("(" + solve(a[zeros[i-1] + 1 : zeros[i]], d + 1) + ")")
        if (i < M - 1):
            ret += str(a[zeros[i]])
    return ret
    

for T in range(1, Cases + 1):
    s = list(map(int, list(input())))
    N = len(s)
    print("Case #{}: ".format(T), solve(s, 0))