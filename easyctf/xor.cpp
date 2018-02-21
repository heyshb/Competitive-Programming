#include <bits/stdc++.h>

using namespace std;

int main()
{
	char s[100];
	//scanf("%s",s);
	int len = 0;
	char c = getchar();
	while(c != '\n')
	{
		s[len++] = c;
		c = getchar();
	}
	//printf("%s\n",s); 
	for (int i=0;i<=128;i++)
	{
		for (int j=0;j<len;j++)s[j] ^= i;
		for (int j=0;j<len;j++)printf("%c",s[j]);puts("");
		for (int j=0;j<len;j++)s[j] ^= i;
	}
}
