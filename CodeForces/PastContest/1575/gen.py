import random

n = 200000
print(n)
a = []
for i in range(n):
    #a.append(random.randint(1, n))
    a.append(i + 1)
print(' '.join(list(map(str, a))))
