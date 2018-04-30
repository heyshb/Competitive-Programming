import sys
import traceback
import socket
import os
import paramiko
import telnetlib

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

def solve():
	global N,vis,find
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

#52.49.91.111:3241
host = '52.49.91.111'
port = 3241
ssh = telnetlib.Telnet(host,port)
S = ssh.read_until(b'\n')
Case = int(S.split()[1])
S = ssh.read_until(b'\n')
ssh.write(b'TEST\n')
for _ in range(Case):
	tmp = ssh.read_until(b'\n')
	print(tmp)
	tmp = ssh.read_until(b'\n').decode()
	lst = tmp.split()
	#print(lst)
	ret = solve()
	print(ret)
	ret += '\n'
	ssh.write(ret.encode('ascii'))

print(ssh.read_until(b'\n'))