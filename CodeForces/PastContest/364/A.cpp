#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#define push_back pb

using namespace std;

typedef long long LL;
LL gcd(LL a,LL b){return b==0?a:gcd(b,a%b);}
int lowbit(int x){return x&(-x);}

int n,l,v1,v2,k;

int main()
{
	scanf("%d%d%d%d%d",&n,&l,&v1,&v2,&k);
	if (n%k==0) k=n/k;
	else k=n/k+1;
	double ans=double(k*l)/double(k*v1+v2);
	printf("%.9lf\n",ans);
}
