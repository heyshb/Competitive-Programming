import math

def streak(x):
	for i in range(1,x+1):
		if ((x+i)%(i+1)!=0):
			return i
	return -1

def gcd(a,b):
	if (b==0):
		return a
	else:
		return gcd(b,a%b)

def alllcm(x):
	res = 1
	for i in range(1,x+1):
		tmp = gcd(res,i)
		res = res * i / tmp
	return res

def calc(a,b):
	print("%d %d %d %d %d\n"%(a,b,alllcm(a-1),alllcm(a),(b-1)/alllcm(a-1) - (b-1)/alllcm(a)))
	return (b-1)/alllcm(a) - (b-1)/alllcm(a+1)

def P(s,N):
	res = calc(s,N-1)
	return res

ans = 0
for i in range(1,15):
	print("%d %d"%(i,streak(i)))
for i in range(1,32):
	ans = ans + P(i,4**i)
print(ans)
#print(P(6,1000000))
