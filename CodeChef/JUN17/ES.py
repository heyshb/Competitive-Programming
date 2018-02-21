import math
from decimal import *

eA = 0
eB = 1

def calc(eA,eB,N):
	sum = 0
	flag = 1
	while(N > 10):
		print(len(str(N)))
		tmp = 0
		while (eA > 2*eB):
			eA = eA - eB
			tmp = tmp + N*(N+1)//2
		#b = a / (a-1)
		np = ((eA - eB)*N)//eB
		tmp = tmp + (N + np) * (N + np + 1) // 2
		sum = sum + tmp * flag
		eB = eA - eB
		N = np
		flag = -flag

	for i in range(1,N+1):
			sum = sum + flag * ((i*eA)//eB)
	return int(sum)

up = 10
fac = [2,1,2]
for i in range(2,up+1):
	fac.append(1)
	fac.append(1)
	fac.append(2*i)

eB = 1
eA = 1
for i in range(up*3-1,-1,-1):
	tmpA = eA*fac[i]+eB
	eB = eA
	eA = tmpA
#print("fuck")
#print(eA)
#print(eB)
#print("%.10lf\n"%(eA/eB))
	
#print("done")
s = input()
N = s.split(' ')[0]
print(calc(eA,eB,int(N)))
exit(0)