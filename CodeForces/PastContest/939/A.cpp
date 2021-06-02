#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int f[5010]; 

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&f[i]);
	bool ok = false;
	for (int i=1;i<=N;i++)ok |= (f[f[f[i]]] == i);
	puts(ok?"YES":"NO");
} 
