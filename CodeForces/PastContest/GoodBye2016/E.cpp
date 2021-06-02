#include <bits/stdc++.h>
#define INF 300000ll
using namespace std;

typedef long long LL;

struct Node
{
	LL v[5][5];
	int l,r;
}T[800010];

char s[200010];

void build(int x,int l,int r)
{
	if (l==r)
	{
		for (int i=0;i<5;i++)
			for (int j=0;j<5;j++)T[x].v[i][j] = INF;
		if (s[l] == '2')
		{
			T[x].v[1][0] = 1;
			T[x].v[1][1] = 0;
		}
		else
		{
			T[x].v[0][0] = 0;
			T[x].v[0][1] = 1;
		}
		return;
	}
	for (int i=l;i<=r;i++)
	{
		
	}
}

int Query(int x,int l,int r)
{
	
	if (r<=mid) return Query(x*2, l, r);
	else if (l>mid) return 
}

int main()
{
	int N,Q;
	scanf("%d%d",&N,&Q);
	scanf("%s",s+1);
	build(1,1,N); 
	while(Q--)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		int ans = Query(1,L,R);
		if (ans > N) ans = -1;
		printf("%d\n",ans);
	}
}
