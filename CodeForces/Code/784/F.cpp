#include <bits/stdc++.h>

using namespace std;

int N,A[100010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	sort(A+1,A+N+1);
	int tmp = 0;
	for (int i=1;i<=2e9;i++)tmp++;
	A[N+1] = tmp;
	for (int i=1;i<=N;i++)printf("%d ",A[i]);
}
