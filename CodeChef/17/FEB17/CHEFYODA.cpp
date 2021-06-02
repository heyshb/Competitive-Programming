#include <bits/stdc++.h>
#define PI 3.1415926535 
using namespace std;

int winrate(int N,int M)
{
	int rate1,rate2;
	rate1 = (N*M%2==0);
	rate2 = (N%2==0&&M%2==0);
	return rate1+rate2;
}

/*

bool vis[110][110];
int N,M;
int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,1,-1};

bool ok(int x,int y)
{
	return x>0 && y>0 && x<=N && y<=M;
}

bool mustwin(int x,int y)
{
	vis[x][y] = true;
	for (int i=0;i<4;i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (!ok(nx,ny)) continue;
		if (vis[nx][ny]) continue;
		if (!mustwin(nx,ny)) 
		{
			vis[x][y] = false;
			return true;
		}
	}
	vis[x][y] = false;
	return false;
}
*/

double calc(int M,int N)
{
	//p = C(N,M)/2^N = N*N-1...N-M+1/M!/2^N
	int cnt = 0, nowm = M;
	double res = 1;
	for (int i=N;i>=N-M+1;i--)
	{
		res = res*i;
		while(res>1 && cnt<N) {res/=2;cnt++;}
		while(res>1 && nowm>1) {res/=nowm;nowm--;}
	}
	while(cnt<N){res/=2;cnt++;}
	while(nowm>1){res/=nowm;nowm--;}
	return res;
}

double F(double x)  
{  
    //Simpson公式用到的函数  
    return exp(-x*x/2)/sqrt(2*PI);
    //return 1-sqrt(1-(1-x)*(1-x));
}  
double simpson(double a, double b)//三点Simpson法，这里要求F是一个全局函数  
{  
    double c = a + (b - a) / 2;  
    return (F(a) + 4 * F(c) + F(b))*(b - a) / 6;  
}  
double asr(double a, double b, double eps, double A)//自适应Simpson公式（递归过程）。已知整个区间[a,b]上的三点Simpson值A  
{  
    double c = a + (b - a) / 2;  
    double L = simpson(a, c), R = simpson(c, b);  
    if (fabs(L + R - A) <= 15 * eps)return L + R + (L + R - A) / 15.0;  
    return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);  
}  
double asr(double a, double b, double eps = 1e-9)//自适应Simpson公式（主过程）  
{  
    return asr(a, b, eps, simpson(a, b));  
}  

int main()
{
	/*
	for (N=1;N<=10;N++)
		for (M=1;M<=10;M++)
		{
			memset(vis,false,sizeof(vis));
			printf("%d %d %d\n",N,M,mustwin(N,M));
		}
	*/
	int T,N,M,P,K;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&N,&M,&P,&K);
		int p = winrate(N,M);
		if (p==0) 
		{
			if (P==0) puts("1");
			else puts("0");
		} 
		else if (p==2) puts("1");
		else
		{
			double ans = 0;
			if (K<=3000)
			{
				for (int i=P;i<=K;i++)
				{
					ans += calc(i,K);
				}
			}
			else
			{
				double nico = sqrt(K*0.25),miu = 0.5*K;
				//ans = asr(L+P-1,R)/asr(L,R);
				//printf("%.7lf %.7lf\n",(P-0.5-miu)/nico,(K+0.5-miu)/nico);
				ans = asr((P-0.5-miu)/nico,(K+0.5-miu)/nico);
			}
			printf("%.10lf\n",ans);
		}
	}
}
