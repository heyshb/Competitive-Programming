#include <bits/stdc++.h>

using namespace std;

int N;
double X[100010],Y[100010];

double dist(double X1,double Y1,double X2,double Y2)
{
	return sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
}

int main()
{
	scanf("%d",&N);
	for (int i=0;i<N;i++)scanf("%lf%lf",&X[i],&Y[i]);
	double ans = 1e15;
	for (int i=0;i<N;i++)
	{
		int L = (i-1+N)%N, R = (i+1)%N;
		double LL = dist(X[L],Y[L],X[R],Y[R]);
		double S = fabs((X[L]-X[i])*(Y[R]-Y[i])-(X[R]-X[i])*(Y[L]-Y[i]));
		double H = S/LL/2;
		ans = min(H,ans);
	}
	printf("%.10lf\n",ans);
}
