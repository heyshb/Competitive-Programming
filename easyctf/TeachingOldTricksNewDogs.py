N = int(input())
s = input()

def gao(c,N):
	if (c == ' '):
		return c
	v = ord(c)
	v -= N
	#print(v)
	if (v < 97):
		v += 26
	return chr(v)

for c in s:
	print(gao(c,N),end="")