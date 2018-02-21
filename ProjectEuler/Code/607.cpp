#include <bits/stdc++.h>

using namespace std;

double b[6];

double dis(double X1,double Y1,double X2,double Y2)
{
	return sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2));
}

double calc(double x,int dep)
{
	//printf("%.3lf %d\n",x,dep);
	if (dep == 5)
		//return dis(x,x+b[5],50,0)/10.0;
		return 0;
	double res = 0;
	//if (dep == 0)
	//	res = dis(-50,0,x,x+b[0])/10.0;
	if (dep == 0) 
	{
		//printf("%.10lf %.10lf\n",x,x+b[0]);
		//printf("%.10lf %.10lf\n",x,res);
	}
	double L = x+10*sqrt(2), R = x+10*(sqrt(2));
	double mid1,mid2,d1,d2,res1,res2;
	for (int i=1;i<=1;i++)
	{
		mid1 = (2*L + R)/3.0;
		mid2 = (L + 2*R)/3.0;
		d1 = dis(x,x+b[dep],mid1,mid1+b[dep+1])/(9.0-dep);
		d2 = dis(x,x+b[dep],mid2,mid2+b[dep+1])/(9.0-dep);
		//printf("%.3lf\n",d1);
		res1 = calc(mid1,dep+1) + d1;
		res2 = calc(mid2,dep+1) + d2;
		if (res1 < res2)
			R = mid2;
		else
			L = mid1;
	}
	return res + res1;
}

int main()
{
	b[0] = 25*sqrt(2);
	b[1] = 15*sqrt(2);
	b[2] = 5*sqrt(2);
	b[3] = -5*sqrt(2);
	b[4] = 15*sqrt(2);
	b[5] = 25*sqrt(2);
	//calc(-25*sqrt(2),0);
	
	double L = -50,R = 0;
	for (int i=1;i<=20;i++)
	{
		printf("%d\n",i); 
		printf("%.10lf %.10lf\n",L,R);
		double mid1 = (2*L + R)/3.0;
		double mid2 = (L + 2*R)/3.0;
		if (calc(mid1,0) < calc(mid2,0))
			R = mid2;
		else
			L = mid1;
	}
	printf("%.12lf\n",calc(L,0));
}
