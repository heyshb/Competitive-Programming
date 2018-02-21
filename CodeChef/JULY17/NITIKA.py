def modify(str):
	return str.capitalize()

def modify2(str):
	return str.upper()[0]+". "

T = int(input());
for i in range(0,T):
	s = input()
	words = s.split(' ');
	for j in range(0,len(words)-1):
		if (words[j] != ""):
			print(modify2(words[j]),end = '')
	print(modify(words[len(words)-1]))

