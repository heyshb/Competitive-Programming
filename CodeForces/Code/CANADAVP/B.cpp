#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
char s[30],seat;
LL row;

int main()
{
	row=0;
	scanf("%s",s+1);	
	int len=strlen(s+1);
	seat=s[len];
	for (int i=1;i<len;i++)row=row*10+s[i]-'0';
	LL tmp=(row-1)/4,ans=0;
	ans=tmp*16;
	if (row-4*tmp==2||row-4*tmp==4) ans+=7;
	//printf("%I64d\n",ans);
	if (seat>='d') ans+='f'-seat+1;
	else ans+=seat-'a'+4;
	printf("%I64d\n",ans);
}
