import sys
import traceback
import socket
import os
import paramiko

N = 0
lst = []
vis = []
find = False

def match(s1,s2):
	if (len(s1) > len(s2)):
		return (s1[0:len(s2)] == s2)
	else:
		return (s2[0:len(s1)] == s1)

def sub(s1,s2):
	if (len(s1) > len(s2)):
		return s1[len(s2):len(s1)]
	else:
		return s2[len(s1):len(s2)]

def dfs(delta):
	global vis,find
	#print(delta)
	if (delta == ''):
		find = True
		return 0
	for i in range(N):
		if ((not vis[i]) and match(lst[i],delta)):
			#print("match %s %s %d"%(lst[i],delta,i))
			vis[i] = True
			dfs(sub(delta,lst[i]))
			if (find):
				return 0
			vis[i] = False

def solve(S):
	global lst,N,vis,find
	lst = S.split(' ')
	N = len(lst)
	#print(lst)
	#print(N)
	vis = [False] * N
	#print(vis)
	find = False
	for i in range(N):
		vis[i] = True
		dfs(lst[i])
		if (find):
			ret = ''
			for j in range(N):
				if (vis[j]):
					if (ret != ''):
						ret += ','
					ret += str(j+1)
			return ret
		vis[i] = False
	return 'boooom'


for i in range(10):
	S = input()
	print(solve(S))