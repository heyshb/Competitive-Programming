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

s = input()
print(bytes(s,"utf8"))
#print(mystery(s))
#print(binascii.hexlify(bytes('hello',"utf-8")))