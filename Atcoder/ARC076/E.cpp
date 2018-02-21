#include <bits/stdc++.h>

using namespace std;

int R,C,N; 
vector<pair<int,int> >p;
int s[100010];

int trans(int x,int y)
{
	if (x>0 && x<R && y>0 && y<C) return -1;
	if (y==0) return x;
	if (x==R) return R+y;
	if (y==C) return R+C+(R-x);
	//x=0
	return 2*R+2*C-y;
}

bool vis[100010];

int main()
{
	scanf("%d%d%d",&R,&C,&N);
	for (int i=1;i<=N;i++)
	{
		int x,y,p1,p2;
		scanf("%d%d",&x,&y);
		p1 = trans(x,y);
		scanf("%d%d",&x,&y);
		p2 = trans(x,y);
		//printf("AFT: %d %d\n",p1,p2);
		if (p1==-1 && p2==-1) continue;
		if (p1 < p2) swap(p1,p2);
		if (p1==-1 || p2==-1)
		{
			//printf("%d %d x2\n",p1,i);
			p.push_back(make_pair(p1,i));
			p.push_back(make_pair(p1,i));
		}
		else
		{
			//printf("%d %d %d %d\n",p1,i,p2,i);
			p.push_back(make_pair(p1,i));
			p.push_back(make_pair(p2,i));
		}
	}
	sort(p.begin(),p.end());
	int M = p.size()-1;
	memset(vis,false,sizeof(vis));
	int cnt = 0;
	bool ok = true;
	for (int i=0;i<=M;i++)
	{
		int pos = p[i].first, num = p[i].second;
		//printf("%d %d\n",pos,num);
		if (vis[num])
		{
			if (cnt != s[num])
			{
				//puts("HERE!");
				ok = false;
			}
			cnt--;
		}
		else
		{
			vis[num] = true;
			s[num] = ++cnt;
		}
		//printf("cnt = %d\n",cnt);
	}
	puts(ok?"YES":"NO");
}
