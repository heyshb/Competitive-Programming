#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int A[1010],B[1010],C[1010];
bool vis[1010];

bool check()
{
	memset(vis,false,sizeof(vis));
	int cnt = 0;
	for (int i=1;i<=N;i++)
	if (!vis[C[i]])
	{
		vis[C[i]] = true;
		cnt++;
	}
	return cnt == N;
}

int main()
{
	scanf("%d",&N);
	int cnt = 0;
	vector<int> dif;
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	for (int i=1;i<=N;i++)scanf("%d",&B[i]);
	for (int i=1;i<=N;i++)
	if (A[i] != B[i])
		dif.push_back(i);
	assert(dif.size() <= 2 && dif.size() > 0);
	if (dif.size() == 1)
	{
		memset(vis,false,sizeof(vis));
		for (int i=1;i<=N;i++)
		if (A[i] == B[i])
			vis[A[i]] = true;
		for (int i=1;i<=N;i++)C[i] = A[i];
		for (int i=1;i<=N;i++)
		if (!vis[i])
			C[dif[0]] = i;
	}
	else
	{
		for (int i=1;i<=N;i++)C[i] = A[i];
		C[dif[0]] = A[dif[0]];
		C[dif[1]] = B[dif[1]];
		if (!check())
		{
			C[dif[0]] = B[dif[0]];
			C[dif[1]] = A[dif[1]];
		}
	}
	for (int i=1;i<=N;i++)printf("%d%c",C[i]," \n"[i==N]);
}
