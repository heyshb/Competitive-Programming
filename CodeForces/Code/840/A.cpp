#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct st
{
	int BB,pos;
}t[200010];
bool cmp(st a,st b){return a.BB < b.BB;}
int N,A[200010],B[200010],ans[200010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	for (int i=1;i<=N;i++)scanf("%d",&B[i]),t[i].pos = i,t[i].BB = B[i];
	sort(A+1,A+N+1);
	reverse(A+1,A+N+1);
	sort(t+1,t+N+1,cmp);
	for (int i=1;i<=N;i++)ans[t[i].pos] = A[i];
	for (int i=1;i<=N;i++)printf("%d%c",ans[i],i==N?'\n':' ');
}
