#include <bits/stdc++.h>

using namespace std;

char Key[] = "AeVNrSzB";
char s[100] = "6504c39fc293c2abc3abc2bac2b56bc3a53d280755c395c28173c39d6dc2b8c2b7c28a39c2ab7bc3a4c39f47";
int len;
int gg(char c)
{
	if (c >= 'a') return 10 + c - 'a';
	return c - '0';
}
int gao(int x)
{
	int c1 = s[x], c2 = s[x + 1];
	printf("%d %d %d\n",c1,c2,16 * gg(c1) + gg(c2));
	return 16 * gg(c1) + gg(c2);
}

int main()
{
	len = strlen(s);
	//printf("%d\n",len);
	int s2[100];
	int len2 = 0;
	for (int i=0;i<len;i+=2)
	{
		s2[len2++] = gao(i);
	}
	for (int i=0;i<len2;i++)
	{
		//printf("%d\n",s2[i]);
		s2[i] = s2[i] ^ ((i * Key[i % 8]) % 256);
		
		printf("%c\n",s2[i]);
	}
	//printf("%s\n",s2);
}
