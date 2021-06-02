import random

def rd2():
    return random.randint(0,1)

N = 3
print(N)
print(1,1,1)
for i in range(N - 1):
    print(rd2(),rd2(),rd2())
print(1,1,1)
for i in range(N - 1):
    print(rd2(),rd2(),rd2())
    