#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int N,B[100010];
struct v
{
	int A,P,pos;
}E[100010];

bool cmp(v a,v b)
{
	return a.P<b.P;
}

int main()
{
	int L,R;
	scanf("%d%d%d",&N,&L,&R);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&E[i].A);
	}
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&E[i].P);
		E[i].pos=i;
	}
	sort(E+1,E+N+1,cmp);
	
	int now = L, lastv = -2147483647;
	bool flag = true;
	for (int i=1;i<=N;i++)
	{
		//printf("sol %d %d %d\n",E[i].A,E[i].P,E[i].pos);
		while(now - E[i].A <= lastv && now<=R)
		{
			now++;
		}
		
		
		lastv = now - E[i].A;
		//printf("%d %d\n",now,lastv);
		if (now>R)
		{
			flag = false;
			break;
		}
		B[E[i].pos] = now;
	}
	if (!flag)
		puts("-1");
	else
		for (int i=1;i<=N;i++) printf("%d%c",B[i],i==N?'\n':' ');
}
