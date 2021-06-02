#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[2][110];

int main()
{
	scanf("%s",s[0]);
	scanf("%s",s[1]);
	int N;
	printf("%s %s\n",s[0],s[1]);
	scanf("%d",&N);
	while(N--)
	{
		char kill[110],newvic[110];
		scanf("%s",kill);
		scanf("%s",newvic);
		if (strcmp(kill,s[0])==0)
		{
			printf("%s %s\n",newvic,s[1]);
			memset(s[0],0,sizeof(s[0]));
			int len=strlen(newvic);
			for (int i=0;i<len;i++)
				s[0][i] = newvic[i];
		}
		else
		{
			printf("%s %s\n",newvic,s[0]);
			memset(s[1],0,sizeof(s[1]));
			int len=strlen(newvic);
			for (int i=0;i<len;i++)
				s[1][i] = newvic[i];
		}
	}
}
