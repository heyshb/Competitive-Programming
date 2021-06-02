N = 100
M = 200
from random import randint
print(N, M)
for _ in range(M):
    while(True):
        u = randint(1, N)
        v = randint(1, N)
        if (u != v):
            break
    if (u > v):
        u, v = v, u
    print(u, v)
    