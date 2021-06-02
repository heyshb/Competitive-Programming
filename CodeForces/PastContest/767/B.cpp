#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL TS,TF,T;
int N,now;
LL t[100010],sum,edtm = 0;
LL minwait = 1e15,anst;

void check(LL tm)
{
	if (tm<TS) tm = TS;
	while(now<=N && t[now]<=tm)
	{
		if (edtm>=t[now])
			edtm += T;
		else
			edtm = t[now] + T;
		now++;
	}
	if (edtm < tm)
	{
		minwait = 0;
		anst = tm;
		return;
	}
	if (edtm + T >= TF) return;
	if (edtm - tm < minwait)
	{
		minwait = edtm - tm;
		anst = tm;
		return;
	}	
}

int main()
{
	scanf("%I64d%I64d%I64d\n",TS,TF,T);
	TF--;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%I64d",&t[i]);
		if (t[i]<TS) t[i] = TS;
	}
	if (t[1]>TS)
	{
		printf("%I64d\n",TS);
		return 0;
	}
	now = 1;
	sum = 0;
	for (int i=1;i<=N;i++)
	{
		check(t[i]-1);
	}
	printf("%I64d\n",anst);
}
