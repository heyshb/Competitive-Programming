import collections
Cases = int(input())

'''
{' ': 2766, '.': 1688, 'y': 1189, 'a': 1112, 'r': 1078, 'b': 975, 'p': 951, 'c': 951, 'o': 939, 'd': 696, 'e': 659, 'n': 478, 'j': 429, 'm': 414, 'g': 331, 'l': 317, 'f': 316, ',': 269, 'u': 259, 'i': 232, 'x': 207, 'k': 200, 't': 170, 'w': 149, 'v': 139, '-': 54, '1': 53, '8': 35, '9': 32, "'": 31, '3': 18, '0': 17, 'q': 16, '2': 15, '(': 14, ')': 14, 'h': 13, ';': 12, '7': 12, '4': 10, '5': 10, '6': 7, 'z': 2, 's': 1}
'''

dic = {}
cnt = []

def code(s1, s2):
    N = len(s1)
    if (len(s2) != N):
        print('!!!!!')
        exit(0)
    for i in range(N):
        if (s1[i] in dic and dic[s1[i]] != s2[i]):
            print('!!!!!')
            exit(0)
        dic[s1[i]] = s2[i]

for ch in '0123456789 ()':
    dic[ch] = ch
dic['.'] = 'e'
dic['y'] = 't'
dic['d'] = 'h'
dic['o'] = 's'
dic['l'] = 'p'
dic['y'] = 't'
dic['m'] = 'm'
dic['x'] = 'b'
dic['p'] = 'r'
dic['a'] = 'a'
dic['f'] = 'y'
code('ofmldrbf', 'symphony')
code('jrmlro.e', 'composed')
dic['t'] = 'k' #?
dic['k'] = 'v'
dic['c'] = 'i'
dic['n'] = 'l'
dic['u'] = 'f'
code('x.jago.', 'because')
dic[','] = 'w'
dic['v'] = '.'
dic['i'] = 'g'
code('\',.pyf','qwerty')
dic['q'] = 'x'
dic['w'] = ','
dic[';'] = 'z'
dic['-'] = '\''
dic['h'] = 'j'
dic['z'] = '/'
dic['s'] = ';'


for T in range(1, Cases + 1):
    print('Case #%d: '%(T), end='')
    s = input()
    ret = ''.join([dic[ch] if ch in dic else '!!!!!!!!!' for ch in s])
    print(ret)
    
#print(sorted(list(dic.values())))
#print(sorted(list(dic.keys())))