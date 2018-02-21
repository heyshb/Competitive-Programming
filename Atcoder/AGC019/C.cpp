#include <bits/stdc++.h>

using namespace std;

double pi = acos(-1);
int N;
struct point
{
	int x,y;
	void read(){scanf("%d%d",&x,&y);}
}p1,p2;
vector<point>p;
bool between(int a,int l,int r)
{
	if (l > r) swap(l,r);
	return (a >= l && a <= r);
}
bool bet(point a,point l,point r)
{
	return between(a.x,l.x,r.x) && between(a.y,l.y,r.y);
}
bool cmp(point a,point b)
{
	return a.x < b.x;
}
bool cmp2(point a,point b)
{
	return abs(a.y - p1.y) < abs(b.y - p1.y);
}
int stk[200010];
int f[200010];

int main()
{
	p1.read();p2.read();
	scanf("%d",&N);
	for (int i=1;i<=N;i++)stk[i] = -1;
	point tmp;
	for (int i=1;i<=N;i++)
	{
		tmp.read();
		if (bet(tmp,p1,p2)) p.push_back(tmp);
	}
	if (p1.x > p2.x) swap(p1,p2);
	sort(p.begin(),p.end(),cmp);
	int ma = 0;
	for (int i=0;i<p.size();i++)
	{
		//printf("!!!!!%d %d\n",p[i].x,p[i].y);
		int l = 0, r = ma;
		if (ma == 0) f[i] = 1;
		else
		{
			if (cmp2(p[stk[ma]],p[i])) 
			{
				//puts("ahahah");
				f[i] = ma + 1;
			}
			else
			{
				while(l != r-1)
				{
					int mid = (l + r) >> 1;
					//printf("%d\n",mid);
					assert(mid); 
					if (cmp2(p[stk[mid]],p[i]))
						l = mid;
					else r = mid;
				}
				if (l==0) f[i] = 1;
				else f[i] = f[stk[l]] + 1; 
			}
		}
		ma = max(ma,f[i]);
		
		if (stk[f[i]] == -1 || cmp2(p[i],p[stk[f[i]]]))
			stk[f[i]] = i;
			
		//printf("%d\n",f[i]);
		//for (int i=1;i<=ma;i++)printf("%d ",stk[i]);puts("");
	}
	//printf("%d\n",ma);
	double ans = 100.00*(abs(p1.x-p2.x) + abs(p1.y-p2.y));
	//printf("%.10lf %.10lf\n",pi,ans);
	ans += ma * (5 * pi - 20);
	if (ma == min(abs(p1.x-p2.x),abs(p1.y-p2.y)) + 1) ans += (5 * pi);
	printf("%.15lf\n",ans); 
}
