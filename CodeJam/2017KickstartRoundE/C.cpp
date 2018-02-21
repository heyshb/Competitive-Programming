#include <bits/stdc++.h>

using namespace std;

struct point
{
	int x,y,z;
}p[110];

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		int mi = 100000, ma = -100000;
		for (int i=1;i<=3;i++)
		{
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
			mi = min(mi,p[i].x);
			ma = max(ma,p[i].x);
		}
		double ans;
		printf("Case #%d: %.10lf\n",_,(ma-mi)/6.0);
	}
}
