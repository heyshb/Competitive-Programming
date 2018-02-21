#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

unordered_map<int,int>cnt; 

int main()
{
	int N,M;
	scanf("%d",&N);
	bool ok = true;
	int tmp;
	for (int i=1;i<=N;i++)scanf("%d",&tmp),cnt[tmp]++;
	scanf("%d",&M);
	for (int i=1;i<=M;i++){scanf("%d",&tmp);if (cnt[tmp]-- == 0) ok = false;}
	puts(ok?"YES":"NO"); 
}
