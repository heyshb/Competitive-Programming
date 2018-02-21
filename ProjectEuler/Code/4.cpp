#include <bits/stdc++.h>

using namespace std;

int s[20];

bool ispar(int x)
{
	int len = 0;
	do
	{
		s[++len] = x%10;
		x/=10;
	}while(x);
	for (int i=1;i<=len;i++)
	if (s[i] != s[len+1-i]) return false;
	return true;
}

int main()
{
	int ans=0; 
	for (int i=100;i<=999;i++)
		for (int j=i;j<=999;j++)
		if (ispar(i*j)) ans=max(ans,i*j);
	printf("%d\n",ans);
}
