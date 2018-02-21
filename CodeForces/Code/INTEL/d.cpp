#include <bits/stdc++.h>

using namespace std;

int N,a[100010],b[100010];
unordered_map<int,bool>vis;

bool check(int up)
{
	vis.clear();
	for (int i=N;i>=1;i--)
	{
		b[i]=a[i];
		while(b[i]>0)
		{
			if (b[i]>up || vis[b[i]]) b[i]/=2;
			else break;
		}
		if (b[i]==0) return false;
		vis[b[i]]=true;
	}
	return true;
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]);
	sort(a+1,a+N+1);
	int L=0,R=1000000000;
	while(L!=R-1)
	{
		
		int mid=(L+R)>>1;
		//printf("%d %d %d\n",L,R,mid);
		if (check(mid)) R=mid;
		else L=mid; 
	} 
	check(R);
	for (int i=1;i<=N;i++)printf("%d ",b[i]);
}
