def fac(n):
    res = 1
    for i in range(1,n+1):
        res*=i
    return res

def C(n,m):
    return fac(n)/fac(m)/fac(n-m)

def calc2(n,m):
    return 0

#for n elements, divide them into m groups and not continuous
def calc1(n,m):
    return C(n-1,m-1)*calc2(n,m)

def calc(N):
    return 0

N = 10
f = [0,1]#no c
g = [0,0]#1 c

#F: 321 132 213
#G: 312 231
#
#
for i in range(2,N+1):
    f.append(f[i-1]*(i-1) + g[i-1])
    g.append(g[i-1]*(i-2) + f[i-1])
    print("%d %d %d\n"%(i,f[i],g[i]))
print(calc(N))