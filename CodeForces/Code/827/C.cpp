#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
char str[100010];
int s[4][11][10][100010];
int lowbit(int x){return x&-x;}
void add(int ch,int p1,int p2,int x,int y){while(x<=N){s[ch][p1][p2][x] += y;x+=lowbit(x);}}
int getsum(int ch,int p1,int p2,int x){int sum=0;while(x){sum+=s[ch][p1][p2][x];x-=lowbit(x);}return sum;}

int trans(char x)
{
	if (x=='A') return 0;
	if (x=='T') return 1;
	if (x=='C') return 2;
	if (x=='G') return 3;
}

int main()
{
	scanf("%s",str+1);
	N = strlen(str+1);
	for (int i=1;i<=N;i++)
		for (int p1=1;p1<=10;p1++)
		{
			int ch = trans(str[i]);
			int p2 = i%p1;
			//printf("ADD %d %d %d %d %d\n",ch,p1,p2,i,1);
			add(ch,p1,p2,i,1);
		}
	int M;
	scanf("%d",&M);
	while(M--)
	{
		int type;
		scanf("%d",&type);
		if (type == 2)
		{
			int L,R;
			char e[15];
			scanf("%d%d",&L,&R);
			scanf("%s",e);
			int p1 = strlen(e);
			int ans = 0;
			for (int i=0;i<p1 && L+i<=R;i++)
			{
				int ch = trans(e[i]);
				//printf("get(%d %d %d %d) - get(%d %d %d %d)\n",ch,p1,(L+i)%p1,R,ch,p1,(L+i)%p1,L-1);
				ans += getsum(ch,p1,(L+i)%p1,R) - getsum(ch,p1,(L+i)%p1,L-1);
			}
			printf("%d\n",ans);
		}
		else
		{
			int pos;
			char e[2];
			scanf("%d",&pos);
			scanf("%s",e);
			int ch = trans(e[0]);
			int ch0 = trans(str[pos]);
			for (int p1=1;p1<=10;p1++)
			{
				int p2 = pos%p1;
				add(ch0,p1,p2,pos,-1);
				add(ch,p1,p2,pos,1);
			}
			str[pos] = e[0];
		}
	}
}
