#include <bits/stdc++.h>

using namespace std;

struct milk
{
	int pos,date;
}mi[1000010];

typedef long long LL;
int N,M,MAXV,K;
LL sum[10000010];
vector<int>expire;

int newend;

bool cmp(milk a,milk b)
{
	return a.date>b.date;
}

bool check(int v)
{
	bool flag = true;
	for (int i=1;i<=v;i++)sum[mi[i].date]++;
	LL res = 0;
	for (int i=0;i<newend;i++)
	{
		int now = expire[i];
		res+=sum[now];
		if (res>LL(K)*LL(now+1))
		{
			flag = false;
			break;	
		}
	}
	for (int i=1;i<=v;i++)sum[mi[i].date]--;
	return flag;
}

int main()
{
	memset(sum,false,sizeof(sum));
	scanf("%d%d%d",&N,&M,&K);
	for (int i=1;i<=N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		sum[tmp]++;
		expire.push_back(tmp);
	}
	for (int i=1;i<=M;i++)
	{
		scanf("%d",&mi[i].date);
		mi[i].pos = i;
		expire.push_back(mi[i].date);
	}
	sort(mi+1,mi+M+1,cmp);
	sort(expire.begin(),expire.end());
	newend = unique(expire.begin(),expire.end())-expire.begin();
	//printf("UNIQUE = %d\n",newend);
	//for (int i=0;i<newend;i++)printf("%d ",expire[i]);puts("");
	if (!check(0))
	{
		puts("-1");
		return 0;
	}
	else
	{
		int l = 0,r = M,mid;
		while(l<r-1)
		{
			mid = (l+r)>>1;
			if (check(mid))
				l = mid;
			else
				r = mid;
		}
		if (check(r)) l = r;
		printf("%d\n",l);
		for (int i=1;i<=l;i++)printf("%d ",mi[i].pos);
	}
}
