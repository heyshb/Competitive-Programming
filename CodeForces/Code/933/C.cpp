#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
double x[10],y[10],r[10];
bool ok[10];

double sqr(double X)
{
	return X * X;
}

double dis(int v1,int v2)
{
	return (x[v1] - x[v2]) * (x[v1] - x[v2]) + (y[v1] - y[v2]) * (y[v1] - y[v2]);
}

double incir(double X,double Y,int v)
{
	return sqr(X-x[v]) + sqr(Y-y[v]) + 1e-6 < r[v] * r[v];
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
	if (N == 1) return 0*puts("2");
	if (N == 2)
	{
		if (x[1] == x[2] && y[1] == y[2] && r[1] == r[2]) return 0*puts("2");
		if ()
		if (dis(1,2) < sqr(r[1] + r[2]) + 1e-5) return 0*puts("4");
		return 0*puts("3");
	}
	
} 
