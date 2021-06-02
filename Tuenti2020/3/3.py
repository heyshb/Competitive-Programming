# coding='utf-8'
from collections import Counter

valid_letters={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','ñ','o','p','q','r','s','t','u','v','w','x','y','z','á','é','í','ó','ú','ü'}

def trans(ch):
    if (ch in valid_letters):
        return ch
    return ' '

with open('pg17013.txt', encoding = 'utf-8') as f:
    book = ''.join([c if c in valid_letters else ' ' for c in f.read().lower()]).split()
    book = list(filter(lambda x:len(x)>2, book))
    result = Counter(book)
    result = sorted(result.items(), key=lambda x:(-x[1],x[0]), reverse=False)

#print(result)
dic = {}
for i in range(len(result)):
    dic[result[i][0]] = i
with open('submitInput.txt', encoding = 'utf-8') as f:
    Cases=int(f.readline())
    for T in range(Cases):
        query = f.readline().strip()
        if (ord(query[0])>=48 and ord(query[0])<=57):
            idx = int(query) - 1
            print("Case #{}: {} {}".format(T+1, result[idx][0], result[idx][1]))
        else:
            idx = dic[query]
            print("Case #{}: {} #{}".format(T+1, result[idx][1], idx + 1))