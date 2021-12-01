def gao(n, a, b, m):
    if b == 0:
        return n * (a // m)
    if a >= m:
        return n * (a // m) + gao(n, a % m, b, m)
    if b >= m:
        return (n - 1) * n // 2 * (b // m) + gao(n, a, b % m, m)
    return gao((a + b * n) // m, (a + b * n) % m, m, b)
 
def work1(H, M, A, a, b, m):
    xp = (-a - 1) // b + 1
    # print("???", xp, H - xp, a + b * xp, b, m)
    return gao(H - xp, a + b * xp, b, m) + H - xp
 
def bf(H, M, A):
    cnt = 0
    for i in range(H):
        for j in range(M):
            if -A <= M * i - (H - 1) * j <= A:
                cnt += 1
    return cnt
 
INF = 10 ** 30
H, M, A = map(int, input().split())
ans = H * M
# right_bot
ans -= work1(H, M, A, 1 - H - A * INF, M * INF, (H - 1) * INF)
# print(ans)
# left_top
xp = ((M - 1) * (H - 1) - A - 1) // M + 1
ret = xp * M - gao(xp, A, M, H - 1) - xp
# print(xp, gao(xp, A, M, H - 1))
ans -= ret
print(ans)
print(bf(H, M, A))