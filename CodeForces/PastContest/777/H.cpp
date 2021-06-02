#include <bits/stdc++.h>

using namespace std;

char A[1010];
char B[1010][1010]; 
int N,M;
typedef long long LL;
LL c[10];
LL f[1010][1010];

int main()
{
	scanf("%s",A+1);
	M = strlen(A+1);
	reverse(A+1,A+M+1);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%s",B[i]+1);
		int len = strlen(B[i]+1);
		reverse(B[i]+1,B[i]+len+1);
		for (int j=len+1;j<=M;j++)
			B[i][j] = '0';
		//printf("%s\n",B[i]+1);
	}
	for (int i=0;i<10;i++)scanf("%I64d",&c[i]);
}
