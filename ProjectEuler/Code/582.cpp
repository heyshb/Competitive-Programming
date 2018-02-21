#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool issquare(LL x)
{
	LL sq = LL(sqrt(x)+0.5);
	return sq*sq==x;
}

int main()
{
	//freopen("582.txt","w",stdout);
	for (int k=1;k<=15;k+=2)
	{
		int cnt = 0;
		for (LL a=1;a<=10000000;a++)
		{
			LL b=a+k,c;
			c = a*a+b*b+a*b;
			if (issquare(c))
			{
				cnt++;
				printf("%d %lld %lld %lld\n",k,a,b,LL(sqrt(c)+0.5));
				//break;
			}
			//if (cnt==2) break;
		}
	}
}
