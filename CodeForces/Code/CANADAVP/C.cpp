#include <bits/stdc++.h>

using namespace std;

char s[30],ans[2][30];
int len,x,y;
bool vis[30];

void expand(char c)
{
	if (y-1>0 && (!ans[x][y-1]))
	{
		y--;
	}
	else if (x-1>=0 && (!ans[x-1][y]))
	{
		x--;
	}
	else
	{
		y++;
	}
	ans[x][y]=c;
}

int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	memset(vis,false,sizeof(vis));
	memset(ans,0,sizeof(ans));
	char tw;
	for (int i=1;i<=len;i++)
	{
		if (!vis[s[i]-'A']) vis[s[i]-'A']=true;
		else tw=s[i];
	}
	int A=-1,B;
	for (int i=1;i<=len;i++)
	if (s[i]==tw)
	{
		if (A==-1)
			A=i;
		else B=i;
	}
	//printf("%c %d %d\n",tw,A,B);
	bool flag=true;
	if (B==A+1) flag=false;
	if (!flag) {puts("Impossible");return 0;}
	int mid=B-A-1;
	x=1,y=13-mid/2;
	ans[x][y]=tw;
	bool turn=false;
	for (int i=A+1;i<B;i++)
	{
		if (!turn)
		{
			y++;
			if (y>13)
			{
				y=13;
				x=0;
				turn=true;
			}
		}
		else y--;
		ans[x][y]=s[i];
	}
	x=1,y=13-mid/2;
	for (int i=A-1;i>=1;i--)expand(s[i]);
	for (int i=len;i>B;i--)expand(s[i]);
	printf("%s\n%s\n",ans[0]+1,ans[1]+1);
}
