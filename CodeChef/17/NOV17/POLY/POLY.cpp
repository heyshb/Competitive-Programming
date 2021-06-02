#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
struct func
{
	int A,B,C,D;
	double f(double x)
	{
		return A*x*x*x + B*x*x + C*x + D;
	}
	LL f(LL x)
	{
		return 1LL*A*x*x*x + 1LL*B*x*x + 1LL*C*x + 1LL*D;
	}
	void print()
	{
		printf("%dx^3+%dx^2+%dx+%d\n",A,B,C,D);
	}
}e[100010];

struct seg
{
	double L,R;
	func F;
};

int N,Q;
const int RG = 100001;
vector<seg>T[400010];

double po(double a,double b)
{
	if (a < 0) return -pow(-a,b);
	return pow(a,b);
}

double eps = 1e-6;
double getcon(func F1,func F2,double L,double R)
{
	double res = R;
	double a,b,c,d,A,B,C,X1,X2,X3;
	a = F1.A - F2.A;
	b = F1.B - F2.B;
	c = F1.C - F2.C;
	d = F1.D - F2.D;
	//printf("%.2lf %.2lf %.2lf %.2lf\n",a,b,c,d);
	if (fabs(a) < eps)// 2 1 0
	{
		if (fabs(b) < eps)// 1 0
		{
			if (fabs(c) > eps) // 1
			{
				X1 = -d/c;
				if (X1 > L + eps) res = min(res,X1);
			}
		}
		else//2 
		{
			double delta = c*c-4*b*d;
			if (delta > -eps)
			{
				delta = max(delta,0.0);
				X1 = (-c+sqrt(delta))/(2*b);
				X2 = (-c-sqrt(delta))/(2*b);
				if (X1 > L + eps) res = min(res,X1);
				if (X2 > L + eps) res = min(res,X2);
			}
		}
		return res;
	}
	A = b*b - 3*a*c;
	B = b*c - 9*a*d;
	C = c*c - 3*b*d;
	double delta = B*B - 4*A*C;
	//printf("%.3lf %.3lf %.3lf %.3lf\n",A,B,C,delta);
	if (fabs(A) <= eps && fabs(B) <= eps)
	{
		X1 = -b/(3*a);
		if (X1 < R + eps && X1 > L + eps)
			return X1;
	}
	else if (delta > eps)
	{
		double Y1 = A * b + 3 * a * (-B + sqrt(B * B - 4 * A * C)) / 2;
		double Y2 = A * b + 3 * a * (-B - sqrt(B * B - 4 * A * C)) / 2;
		//printf("%.5lf %.5lf\n",Y1,Y2);
		X1 = (- b - (po(Y1, 1.0/3) + po(Y2, 1.0/3))) / (3 * a);
		//printf("%.3lf\n",X1);
		if (X1 < R + eps && X1 > L + eps)
			return X1;
	}
	else if (fabs(delta) <= eps)
	{
		double K = B / A;
		X1 = -b/a + K;
		X2 = -K/2;
		if (X1 > L + eps) res = min(res,X1);
		if (X2 > L + eps) res = min(res,X2);
	}
	else // < 0
	{
		double TT = (2*A*b-3*a*B) / (2*A*sqrt(A));
		double theta = acos(TT);
		X1 = (-b-2*sqrt(A)*cos(theta/3))/(3*a);
		X2 = (-b+sqrt(A)*(cos(theta/3)+sqrt(3)*sin(theta/3)))/(3*a);
		X3 = (-b+sqrt(A)*(cos(theta/3)-sqrt(3)*sin(theta/3)))/(3*a);//fuck you
		if (X1 > L + eps) res = min(res,X1);
		if (X2 > L + eps) res = min(res,X2);
		if (X3 > L + eps) res = min(res,X3);
	}
	return res;
}

vector<seg> Merge(vector<seg> &N1,vector<seg> &N2)
{
	int node1 = 0, node2 = 0;
	double now = 0;
	vector<seg> res;
	while(node1 < N1.size() && node2 < N2.size())
	{
		//printf("%d %d\n",node1,node2);
		double end = min(N1[node1].R,N2[node2].R);
		double con = getcon(N1[node1].F,N2[node2].F,now,end);
		seg tmp;
		tmp.L = now;
		tmp.R = con;
		double midx = (con + now) / 2;
		if (N1[node1].F.f(midx) < N2[node2].F.f(midx))
			tmp.F = N1[node1].F;
		else
			tmp.F = N2[node2].F;
		res.push_back(tmp);
		now = con;
		if (N1[node1].R < now + eps) node1++;
		if (N2[node2].R < now + eps) node2++;
	}
	//puts("fuck");
	while(node1 < N1.size()) res.push_back(N1[node1++]);
	while(node2 < N2.size()) res.push_back(N2[node2++]);
	//puts("done");
	//for (auto t:res) printf("[%.5lf %.5lf] ",t.L,t.R),t.F.print();
	return res;
}

void build(int x,int L,int R)
{
	T[x].clear();
	if (L == R)
	{
		seg tmp;
		tmp.L = 0;
		tmp.R = RG;
		tmp.F = e[L];
		//printf("wow %d\n",x);tmp.F.print();
		T[x].push_back(tmp);
		return;
	}
	int mid = (L + R) >> 1;
	build(x * 2, L, mid);
	build(x * 2 + 1, mid + 1, R);
	//printf("Merge %d %d\n",x*2,x*2+1);
	T[x] = Merge(T[x*2], T[x*2+1]);
}

LL solve(LL x)
{
	int L = 0, R = T[1].size() - 1;
	if (T[1][0].R > x)
		return T[1][0].F.f(x);
	while(L < R - 1)
	{
		int mid = (L + R) >> 1;
		if (T[1][mid].R > x)
			R = mid;
		else
			L = mid;
	}
	return T[1][R].F.f(x);
}

int main()
{
	freopen("POLY.in","r",stdin);
	freopen("POLY.out","w",stdout);
	int Cases;
	scanf("%d",&Cases);
	while(Cases--)
	{	
		scanf("%d",&N);
		for (int i=1;i<=N;i++)scanf("%d%d%d%d",&e[i].D,&e[i].C,&e[i].B,&e[i].A);
		build(1,1,N);
		int Q;
		scanf("%d",&Q);
		while(Q--)
		{
			LL x;
			scanf("%lld",&x);
			printf("%lld\n",solve(x));
		}
	}
}
