#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL inf = 1e15;
struct ticket
{
	int ti,from,to,cost;
}t[300010];

bool cmp(ticket a,ticket b)
{
	if (a.to != b.to)
		return a.to < b.to;
	return a.ti < b.ti;
}
LL ans,start,finish;
int minstart[300020],minfinish[300010],change[300010];
int n,m,k,now,flight;

int lowbit(int x){return x&-x;}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&t[i].ti,&t[i].from,&t[i].to,&t[i].cost);
	
	for(int i=1;i<=n;i++)minfinish[i]=-1;
	sort(t+1,t+m+1,cmp);

	for(int i=m;i>=1;i--)
	if(t[i].from==0)
	{
		if(minfinish[t[i].to]!=-1)
			change[i]=minfinish[t[i].to];
		if(minfinish[t[i].to]==-1||minfinish[t[i].to]>t[i].cost)
			minfinish[t[i].to]=t[i].cost;
	}
	else
	{ 
		now=i; 
		break; 
	}
	
	finish=0;
	
	for(int i=1;i<=n;i++)
		if(minfinish[i]!=-1)
			finish+=minfinish[i];
		else return 0*puts("-1");


	start=0;
	flight=0;
	int j=now+1;
	for(int i=1;i<=n;i++)
		minstart[i]=-1;

	ans=inf;
	for(int i=1;i<=now;i++)
	{
		for(;j<=m&&t[j].ti-t[i].ti<=k;j++)
		{
			finish += change[j] - minfinish[t[j].to];
			minfinish[t[j].to]=change[j];
			if(minfinish[t[j].to]==-1)
			{
				cout<<ans<<endl;
				return 0;
			}
		}
		if(j>m)break;
		if(minstart[t[i].from]==-1)
		{
			minstart[t[i].from]=t[i].cost;
			start+=t[i].cost;
			flight++;
		}
		else if(minstart[t[i].from]>t[i].cost)
		{
			start-=minstart[t[i].from]-t[i].cost;
			minstart[t[i].from]=t[i].cost;
		}
		if(flight==n)ans=min(ans,start+finish);
	}
	if (ans==inf)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
