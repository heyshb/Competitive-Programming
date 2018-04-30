def fuck(S):
	if (S == 'pikachu'):
		return 1
	if (S == 'ka'):
		return 2
	if (S == 'pipi'):
		 return 3
	if (S == 'pichu'):
		 return 4
	if (S == 'pi'):
		 return 5
	if (S == 'chu'):
		 return 6
	if (S == 'pika'):
		 return 7
	return 8

for i in map(fuck,input().split()):
	print(i)
