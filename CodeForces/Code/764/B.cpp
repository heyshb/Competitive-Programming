#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct rec
{
	int x1,y1,x2,y2,num;
}R[500010];
struct point
{
	int x,y,type,num;
};
vector<point> p;
int N;
vector<int> e[500010];

bool cmp1(point a,point b)
{
	if (a.y==b.y) return a.x<b.x; 
	return a.y>b.y;
}
/*
y2 1      2
y1 3      4
   x1     x2
*/
void add(int x,int y)
{
	e[x].push_back(y);
	e[y].push_back(x);
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d%d%d%d".&R[i].x1,&R[i].y1,&R[i].x2,&R[i].y2);
		p.push_back((point){x1,y2,1,i});
		p.push_back((point){x2,y2,2,i});
		p.push_back((point){x1,y1,3,i});
		p.push_back((point){x2,y1,4,i});
		R[i].num = i;
	}
	int nowdown = 0, nowright = 0;
	sort(p.begin(),p.end(),cmp1);
	for (int i=0;i<p.size();i++)
}
