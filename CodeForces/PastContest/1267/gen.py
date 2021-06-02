import random

N = 5
print(N)
for i in range(N):
    t = random.randint(1,5)
    a = random.randint(1,10)
    b = random.randint(a+t, 20)
    print(a,b,t)