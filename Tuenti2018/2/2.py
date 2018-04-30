T = int(input())

for Case in range(T):
	s = input()
	N = len(s)
	ma = 0
	mi = 0
	for i in range(N):
		ma = ma*N+(N-1-i)
	mi = N
	for i in range(N-2):
		mi = mi*N+(i+2)
	print("Case #%d: %d"%(Case+1,ma - mi))