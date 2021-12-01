import random


T = 1000
print(T)
for _ in range(T):
    n = random.randint(3, 70)
    print(n)
    a = [random.randint(1, 10) for i in range(n)]
    print(' '.join(map(str, a)))