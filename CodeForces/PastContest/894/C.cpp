#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int N,A[1010];
vector<int>ans;

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	for (int i=1;i<=N;i++)
	if (A[i]%A[1] != 0) return 0*puts("-1");
	printf("%d\n",2*N+1);
	for (int i=1;i<=2*N;i++)
	if (i%2==1)
		printf("%d ",A[1]);
	else 
		printf("%d ",A[i/2]);
	printf("%d\n",A[1]);
}
