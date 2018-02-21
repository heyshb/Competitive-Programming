#include <bits/stdc++.h>

using namespace std;

int d,h,m;
char s[5];

int print(int x)
{
	if (x<10) printf("0");
	printf("%d",x);
}

int main()
{
	scanf("%d",&d);
	scanf("%s",s);
	h=(s[0]-'0')*10+s[1]-'0';
	m=(s[3]-'0')*10+s[4]-'0';
	if (d==24)
	{
		if (h>23)
			h%=10;
		if (m>60) m%=10;
	}
	else
	{
		if (h>12)
		{
			if (h%10>0)
				h%=10;
			else
				h=10;
		}
		else if (h==0)
		{
			h=1;
		}
		if (m>60) m%=10;
	}
	print(h);printf(":");print(m);
}
