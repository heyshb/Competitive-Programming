M = 10
N = 3674160
ans = 0
for i in range(1,25):
	str = input()
	arr = str.split(' ')
	a = arr[0]
	b = arr[1]
	print(a)
	print(b)
	ans = ans + (M ** int(a)) * int(b)
print("FUCKYOU")
print(ans)
print(ans%N)
ans = ans // N
print(ans)