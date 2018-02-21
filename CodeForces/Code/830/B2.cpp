#include <bits/stdc++.h>

using namespace std;

int N;
int T[100010];
int lowbit(int x){return x&-x;}
void add(int x,int y){while(x<=N){T[x]+=y;x+=lowbit(x);}}
int getsum(int x){int s=0;while(x){s+=T[x];x-=lowbit(x);}return s;} 
int get(int L,int R){return getsum(R)-getsum(L-1);}
vector<int>pos[100010];
typedef long long LL;

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		pos[tmp].push_back(i);
		add(i,1);
	}
	int p = 0;
	LL ans = 0;
	for (int i=1;i<=100000;i++)
	if (pos[i].size())
	{
		if (p < pos[i][0])
		{
			ans += get(p + 1,pos[i][pos[i].size()-1]);
			p = pos[i][pos[i].size()-1];
		}
		else
		{
			int last = -1;
			for (int j=pos[i].size()-1;j>=0;j--)
			if (pos[i][j] < p)
			{
				last = pos[i][j];
				break;
			}
			ans += get(p + 1, N);
			ans += get(1, last);
			p = last;
		}
		for (auto &t:pos[i])
			add(t,-1);
	}
	printf("%lld\n",ans);
}
