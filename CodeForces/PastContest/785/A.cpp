#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
int A[100010];

int tr[500010];
int lowbit(int x){return x&-x;}
int getsum(int x){int res = 0;while(x){res+=tr[x];x-=lowbit(x);}return res;}
void add(int x,int y){while(x<=N){tr[x]+=y;x+=lowbit(x);}}

int main()
{
	char s[110];
	scanf("%d",&N);
	int ans = 0;
	while(N--)
	{
		scanf("%s",s);
		if (s[0]=='T') ans+=4;
		if (s[0]=='C') ans+=6;
		if (s[0]=='O') ans+=8;
		if (s[0]=='D') ans+=12;
		if (s[0]=='I') ans+=20;
	}
	printf("%d\n",ans);
}
