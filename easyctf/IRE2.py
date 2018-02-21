#!/usr/bin/env python3
import binascii
key = "AeVNrSzB"
def mystery(s):
	r = ""
	for i, c in enumerate(s):
		r += chr(ord(c)^((i*ord(key[i%len(key)]))%256))
	ss = bytes(r, "utf8")
	print(ss)
	return binascii.hexlify(bytes(r, "utf-8"))

s = "6504c39fc293c2abc3abc2bac2b56bc3a53d280755c395c28173c39d6dc2b8c2b7c28a39c2ab7bc3a4c39f47"
c = binascii.unhexlify(s)
#print(c)
d = c.decode("UTF-8")
print(len(d))
for i in range(28):
	tmp = d[i]
	tmp = chr(ord(tmp) ^ ((i*ord(key[i%len(key)]))%256))
	print(tmp)