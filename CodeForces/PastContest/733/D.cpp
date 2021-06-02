#include <bits/stdc++.h>
#define MOD 1000007
using namespace std;

struct stone
{
	int v[3];
}s[100010];
typedef long long LL;
map<pair<int,int>,int> mp,mp2;
int K,V1,V2;
int ans;

int min3(int x,int y,int z)
{
	x=min(x,y);
	return min(x,z);
}

void get(int x,int y,int z,int num)
{
	if (mp.count(make_pair(x,y)))
	{
		if (min3(z+mp[make_pair(x,y)],x,y)>ans)
		{
			//printf("%d %d\n",z,mp[make_pair(x,y)]);
			ans=min3(z+mp[make_pair(x,y)],x,y);
			K=2;
			V1=mp2[make_pair(x,y)];
			V2=num;
			//printf("%d %d %d %d %d %d\n",x,y,z,V1,V2,ans);
		}
	}
}

void ins(int x,int y,int z,int num)
{
	if (mp.count(make_pair(x,y)))
	{
		if (z>mp[make_pair(x,y)])
		{
			mp[make_pair(x,y)]=z;
			mp2[make_pair(x,y)]=num;
		}
	}
	else 
	{
		mp[make_pair(x,y)]=z;
		mp2[make_pair(x,y)]=num;
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	ans=0;
	for (int i=1;i<=N;i++)
		for (int j=0;j<3;j++)
		scanf("%d",&s[i].v[j]);
		
	
	for (int i=1;i<=N;i++)
	{
		sort(s[i].v,s[i].v+3);
		if (s[i].v[0]>ans)
		{
			ans=s[i].v[0];
			K=1;
			V1=i;
		}
	}
	//printf("!%d\n",ans);
	/*
	for (int i=1;i<=N;i++)
	{
		for (int j=0;j<3;j++)printf("%d ",s[i].v[j]);puts("");
	}*/
	for (int i=1;i<=N;i++)
	{
		//printf("%d\n",i);
		get(s[i].v[0],s[i].v[1],s[i].v[2],i);
		get(s[i].v[0],s[i].v[2],s[i].v[1],i);
		get(s[i].v[1],s[i].v[2],s[i].v[0],i);
		ins(s[i].v[0],s[i].v[1],s[i].v[2],i);
		ins(s[i].v[0],s[i].v[2],s[i].v[1],i);
		ins(s[i].v[1],s[i].v[2],s[i].v[0],i);
	}
	printf("%d\n",K);
	if (K==1) printf("%d\n",V1);
	else printf("%d %d\n",V1,V2);
	//printf("%d\n",ans);
}
