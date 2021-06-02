import collections

with open('test2.txt', 'rb') as f:
    b = f.read()
    print(len(b))
    print(b)
    ret = ''.join([bin(ib)[2:].zfill(8) for ib in b])
    print(ret)
    cnt = collections.Counter(ret)
    print(cnt)