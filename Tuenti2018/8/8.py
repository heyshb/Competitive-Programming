a = [0] * 200
r = [0] * 200
N = 0

#(d,x,y)
def exgcd(a,b):
	if (b == 0):
		return (a,1,0)
	(d,xp,yp) = exgcd(b,a%b)
	return (d,yp,xp-a//b*yp)

def solve():
	for i in range(1,N):
		c = r[i] - r[i-1]
		(d,x,y) = exgcd(a[i-1],a[i])
		#print((d,x,y))
		if (c%d != 0):
			return -1
		t = a[i] // d
		x = (x*(c//d)%t+t)%t
		r[i] = a[i-1]*x+r[i-1]
		a[i] = a[i-1]*(a[i]//d)
	return r[N-1]


T = int(input())
for Case in range(T):
	global N
	N = int(input())
	for i in range(N):
		#tmp = map(int,input().split(' '))
		tmp = input().split()
		X = int(tmp[0])
		Y = int(tmp[1])
		a[i] = X
		r[i] = (X-Y-i+X)%X
		#print("%d %d"%(a[i],r[i]))
	ans = solve()
	if (ans == -1):
		print("Case #%d: NEVER"%(Case+1))
	else:
		print("Case #%d: %d"%(Case+1,ans))