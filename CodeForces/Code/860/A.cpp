#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[3010];
int N;

bool f(char c)
{
	if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return false;
	return true;
}

bool sm(int l,int r)
{
	for (int i=l;i<=r;i++)
		if (s[l] != s[i]) return false;
	return true;
}

int main()
{
	scanf("%s",s);
	N = strlen(s);
	for (int i=0;i<N;)
	if (f(s[i]))
	{
		int j=i;
		while(j+1<N && f(s[j+1])) j++;
		if (sm(i,j) || j-i+1<3)
		{
			for (int k=i;k<=j;k++)printf("%c",s[k]);
		}
		else
		{
			for (int k=i;k<=j;k++)
			{
				printf("%c",s[k]);
				if (k!=j && (k-i)%2==1) printf(" ");
			}
		}
		i=j+1;
	}
	else
	{
		printf("%c",s[i]);
		i++;
	}
}
