#include <bits/stdc++.h>

using namespace std;

/*
++>
+++>
<[<+>-]<
++++++++++++++++++++++++++++++++++++++++++++++++.

+++++++++>
+++++++>
<[<->-]<
++++++++++++++++++++++++++++++++++++++++++++++++.
*/

char s[1010];

int main()
{
	scanf("%s",s);
	int len = strlen(s),type,pos;
	for (int i=0;i<len;i++)
	{
		if (s[i]=='+')
		{
			type = 1;
			pos = i;
		}	
		if (s[i]=='-')
		{
			type = 2;
			pos = i;
		}
	}
	int v1 = 0, v2 = 0;
	for (int i=0;i<pos;i++)v1=v1*10+s[i]-'0';
	for (int i=pos+1;i<len;i++)v2=v2*10+s[i]-'0';
	for (int i=1;i<=v1;i++)printf("+");
	puts(">");
	for (int i=1;i<=v2;i++)printf("+");
	puts(">");
	if (type==1) puts("<[<+>-]<");
	else
	puts("<[<->-]<");
	puts("++++++++++++++++++++++++++++++++++++++++++++++++.");
}
