#include <bits/stdc++.h>

using namespace std;

double Cos(double Sin)
{
	return sqrt(1 - Sin * Sin);
}

double Tan(double Sin)
{
	return Sin/Cos(Sin);
}

double d = 25*(sqrt(2) - 1);

double calc(double S)
{
	double res = 2*Tan(S)*d;
	for (int i=1;i<=5;i++)
		res += 10 * Tan(S * (10.0-i) / 10); 
	return res;
}

double calc2(double S)
{
	double res = d/Cos(S)/5.0;
	for (int i=1;i<=5;i++)
		res += 10.0 / Cos(S* (10.0-i) / 10) / (10-i);
	return res;
}

int main()
{
	
	double L = 0, R = 0.9;
	for (int i=1;i<=100;i++)
	{
		double mid = (L + R)/2;
		double tmp = calc(mid);
		printf("%.10lf %.10lf\n",mid,tmp);
		if (tmp*tmp > 5000)
			R = mid;
		else
			L = mid;
	}
	printf("%.10lf\n",L);
	printf("%.12lf\n",calc2(L));
}
