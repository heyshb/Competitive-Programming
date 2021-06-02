#include <bits/stdc++.h>

using namespace std;

struct point
{
	double x,y;
	point(){}
	point(double x,double y):x(x),y(y){}
	double operator * (const point &a) const
	{
		return x*a.y-y*a.x;
	}
	double operator ^ (const point &a) const
	{
		return x*a.x+y*a.y;
	}
	point operator + (const point &a) const 
	{
		return point(x+a.x,y+a.y);
	}
	point operator - (const point &a) const 
	{
		return point(x-a.x,y-a.y);
	}
	point operator /(const double &a) const
	{
		return point(x/a,y/a);
	}
}P[4],ans[3];

double eps = 1e-12;

double sgn(double x)
{
	return (x>eps?1:(x+eps<0?-1:0));
}

bool zero(double x)
{
	return (x>0?x:-x)<eps;
}

bool parallel(const point &u1, const point &u2,const point &v1,const point &v2)
{
	return zero((u1-u2)*(v1-v2));
}

bool dotOnlineIn(const point &p, const point &l1, const point &l2)
{
	return zero((p-l2)*(l1-l2)) && (l1.x-p.x)*(l2.x-p.x)<eps && (l1.y-p.y)*(l2.y-p.y)<eps;
}

int decideSide(const point &p1,const point &p2,const point &l1,const point &l2)
{
	return sgn((l1-l2)*(p1-l2)) * sgn((l1-l2) * (p2-l2));
}

point intersection(const point &u1,const point &u2,const point &v1,const point &v2)
{
	return u1+(u2-u1)*(((u1-v1)*(v1-v2))/((u1-u2)*(v1-v2)));
}

int main()
{
	int XX[4],YY[4];
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for (int i=0;i<4;i++)
		{
			scanf("%d%d",&XX[i],&YY[i]);
			P[i].x = XX[i];
			P[i].y = YY[i];
		}
		bool smp = false;
		int w;
		for (int i=0;i<4;i++)
			for (int j=i+1;j<4;j++)
			if (XX[i]==XX[j] && YY[i]==YY[j])
			{
				smp = true;
				w = i;
			}
		if (smp)
		{
			printf("YES");
			for (int i=0;i<4;i++)
			if (i!=w)
				printf(" %.8lf %.8lf",P[i].x,P[i].y);
			puts("");
			continue;
		}
		
		bool p3l1 = false;
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
				for (int k=0;k<4;k++)
				{
					if (i==j || i==k || j==k) continue;
					if (dotOnlineIn(P[i],P[j],P[k]))
					{
						p3l1 = true;
						ans[0] = P[j];
						ans[1] = P[k];
						ans[2] = P[6-i-j-k];
					}
				} 
		if (p3l1)
		{
			printf("YES");
			for (int i=0;i<3;i++)printf(" %.8lf %.8lf",ans[i].x,ans[i].y);
			puts(""); 
		}
	}
}
