from PIL import Image
import random
import math

img = Image.open('large_2.png')

m, n = img.size

fa = list(range(m))

def find(x):
	if (x == fa[x]):
		return x
	tmp = find(fa[x])
	fa[x] = tmp
	return tmp

a = img.getdata()

g = [[0] * m for i in range(n)]
ret = [[0] * m for i in range(n)]
gg = [[0] * n for i in range(m)]

for i in range(n):
    for j in range(m):
        g[i][j] = a[i * m + j]
        gg[j][i] = a[i * m + j]
edges = []
d = [0] * m
for i in range(m):
	print(i)
	for j in range(i+1,m):
		weight = 0
		for k in range(n):
			weight += abs(g[k][i] - g[k][j])
		edges.append((weight,i,j))
edges.sort()
print(len(edges))

print("sort done")

_ = 0

vertices = []

out = [ [] for i in range(m)]

def add(dic, a):
	if not a in dic:
		dic[a] = 0
	dic[a] += 1

print(edges[-1])

for e in edges:
	L = e[1]
	R = e[2]
	if (d[L] == 2 or d[R] == 2 or find(L) == find(R)):
		continue
	_+=1
	#print("add",_)
	d[L]+=1
	d[R]+=1
	out[L].append(R)
	out[R].append(L)
	fa[find(L)] = find(R)

#for i in range(m):
#	print("%d %d"%(i,find(i)))
print("-----")
for i in range(m):
	if (d[i] == 1):
		print(i)
print("-----")
fck = []
for i in range(m):
	if (d[i] == 1):
		last = -1
		now = i
		while(True):
			#print("miaomiao")
			#print(now)
			fck.append(now)
			if (d[now] == 1 and now != i):
				break
			print(now)
			if (out[now][0] == last):
				nxt = out[now][1]
			else:
				nxt = out[now][0]
			last = now
			now = nxt
		break

print("%d %d"%(len(fck),m))

for i in range(m):
	for j in range(n):
		ret[j][i] = g[j][fck[i]]

ans = Image.new('L',(m,n))
t = ans.load()

for i in range(n):
	for j in range(m):
		t[(j,i)] = ret[i][j]


ans.save('large_out.png')
