#include <bits/stdc++.h>

using namespace std;

/*
(1-y)2 + (1-x)2 = 1
1-y = sqrt(1-(1-x)2) 
*/

/*
Assume R = 1
(1 - 1/N * x)^2 = 1 - (1-x)^2
1 - 2/N * x + x^2/N^2 = 1 - 1 + 2x - x^2
1 - 2x/N + x^2/N^2 = 2x - x^2
(1+1/N^2)x^2 - 2(1+1/N)x + 1 = 0 
*/

double F(double x)  
{  
    //Simpson公式用到的函数  
    return 1-sqrt(1-(1-x)*(1-x));
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
double asr(double a, double b, double eps = 1e-6)//自适应Simpson公式（主过程）  
{  
    return asr(a, b, eps, simpson(a, b));  
}  

//(1+1/N^2)x^2 - 2(1+1/N)x + 1 = 0 
double calc(int N)
{
	double s1,s2,div,a = 1+1.0/(N*N), b = -2*(1+1.0/N);
	printf("%.5lf %.5lf %.5lf\n",a,b,div);
	div = (-b-sqrt(b*b-4*a))/(2*a);
	printf("%.5lf %.5lf %.5lf\n",a,b,div);
	s1 = asr(0,1);
	s2 = 0.5*div*div/N + asr(div,1);
	return s2/s1;
}

int main()
{
	int L = 1, R = 100000;
	while(L != R-1)
	{
		int mid = (L+R)>>1;
		double occupy = calc(mid);
		 
		printf("%d %d %d %.8lf\n",L,R,mid,occupy);
		if (occupy < 0.001)
			R=mid;
		else 
			L=mid;
	}
}
