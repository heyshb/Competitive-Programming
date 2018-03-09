#include <bits/stdc++.h>

using namespace std;

struct point
{
	int X,Y;
}t[30],p[510],z[30];

typedef long long LL;
LL sqr(int x){
	return 1LL * x * x;
}

LL dis(point a,point b)
{
	return sqr(a.X - b.X) + sqr(a.Y - b.Y);
}

int main()
{
	int T,P,Z;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)scanf("%d%d",&t[i].X,&t[i].Y);
	scanf("%d",&P);
	for (int i=1;i<=P;i++)scanf("%d%d",&p[i].X,&p[i].Y);
	scanf("%d",&Z);
	for (int i=1;i<=Z;i++)scanf("%d%d",&z[i].X,&z[i].Y);
	
	printf("%d\n",2*P);
	
	for (int i=1;i<=P;i++)
	{
		LL mind = 2e12;
		int ct;
		for (int j=1;j<=T;j++)
		if (dis(p[i],t[j]) < mind)
		{
			mind = dis(p[i],t[j]);
			ct = j;
		}
		
		mind = 2e12;
		int cz;
		for (int j=1;j<=Z;j++)
		if (dis(p[i],z[j]) < mind)
		{
			mind = dis(p[i],z[j]);
			cz = j;
		}
		
		printf("MOVE %d %d 1 %d\n",p[i].X - t[ct].X,p[i].Y - t[ct].Y,ct);
		printf("MOVE %d %d 1 %d\n",z[cz].X - p[i].X,z[cz].Y - p[i].Y,ct);
		
		
		t[ct] = z[cz];
	}
}
