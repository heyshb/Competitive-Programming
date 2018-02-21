#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
int A[1010],B[1010]; 

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	for (int i=1;i<=M;i++){scanf("%d",&B[i]);B[i] = -B[i];}
	sort(B+1,B+M+1);
	for (int i=1;i<=M;i++)B[i] = -B[i];
	int now = 0;
	for (int i=1;i<=N;i++)
	if (!A[i])
		A[i] = B[++now];
	bool incc = true;
	for (int i=2;i<=N;i++)
		if (A[i] <= A[i-1])
			incc = false;
	puts(incc?"No":"Yes");
}
