#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL h,m,a,g;
int main(){
	scanf("%lld%lld%lld",&h,&m,&a);
	g=__gcd(h-1,h*m);
	printf("%lld\n",(a/g*2+1)*g);
}