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
	return sqr(X-x[v]) + sqr(Y-y[v]) + 1e-8 < r[v] * r[v];
}

int rd[1000000];

int main()
{
	r[1] = r[2] = r[3] = 0;
	x[1] = x[2] = x[3] = 100;
	y[1] = y[2] = y[3] = 100;
	srand(time(0));
	for (int i=0;i<1000000;i++) rd[i] = rand() % 5;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
	int now = 0;
	for (double X=-20.134;X<=20;X=X+0.00412)
		for (double Y=-20.123;Y<=20;Y=Y+0.00412)
		{
			now = now + 1;
			if (now == 1000000) now = 0;
			if (rd[now] > 1) continue;
			int bin = 0;
			for (int i=1;i<=N;i++)
			if (incir(X,Y,i)) bin |= (1<<(i-1));
			//printf("%d\n",bin);
			ok[bin] = true;
		}
	int ans = 0;
	for (int i=0;i<8;i++) ans+=ok[i];
	printf("%d\n",ans);
} 
