import math
print(65178*3+65190-17460)
ans=0
up=10**3
for i in range(1,101):
    k = int(input())
    a = int(input())
    b = int(input())
    c = int(input())
    k2 = int(input())
    a2 = int(input())
    b2 = int(input())
    c2 = int(input())
    clast = c2
    clast2 = c
    x0 = a
    lasta = 0
    #print("%d %d %d %d %d %d %d %d\n"%(k,a,b,c,k2,a2,b2,c2))
    if (c>up):
        ans=ans-1
    if (c2>up):
        ans=ans-1
    if (k%2==0):
        while(c<=up):
            ans+=1
            tmp=a
            a=a*3+b-lasta
            lasta=tmp
            b=a+k
            c=math.sqrt(a*a+a*b+b*b)

    else:
        ans+=2
        cn = 14*clast-clast2
        while(cn<=up):
            if (k==11):
                print("%d\n"%(cn))
            ans+=1
            clast2 = clast
            clast = cn
            cn = 14*clast-clast2
print(ans)


