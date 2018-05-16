#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5, MAX_TRIS = N * 6;
typedef double ft;
typedef long long LL;
const ft EPSILON = 1e-6, PI = acos(-1.0);
const ft eps2 = 1e-8;
const ft INF = 1e17;
struct Point {
ft x,y; Point():x(0),y(0){} Point(ft x, ft y):x(x),y(y){}
bool operator ==(Point const& that)const {return x==that.x&&y==that.y;}
bool operator < (Point const& that)const {return x<that.x || (x==that.x && y<that.y);}
};
inline ft sqr(ft x) { return x*x; }
ft dist_sqr(Point const& a, Point const& b){return sqr(a.x-b.x)+sqr(a.y-b.y);}
bool in_circumcircle(Point const& p1, Point const& p2, Point const&p3, Point const& p4)
{
	ft u11 = p1.x - p4.x, u21 = p2.x - p4.x, u31 = p3.x - p4.x;
	ft u12 = p1.y - p4.y, u22 = p2.y - p4.y, u32 = p3.y - p4.y;
	ft u13 = sqr(p1.x) - sqr(p4.x) + sqr(p1.y) - sqr(p4.y);
	ft u23 = sqr(p2.x) - sqr(p4.x) + sqr(p2.y) - sqr(p4.y);
	ft u33 = sqr(p3.x) - sqr(p4.x) + sqr(p3.y) - sqr(p4.y);
	ft det = -u13*u22*u31 + u12*u23*u31 + u13*u21*u32 - u11*u23*u32 - u12*u21*u33 + u11*u22*u33;
	return det > EPSILON;
}
ft side(Point const& a, Point const& b, Point const& p) 
{
	return (b.x-a.x)*(p.y-a.y) - (b.y-a.y)*(p.x-a.x);
}
typedef int SideRef; 
struct Triangle; 
typedef Triangle* TriangleRef;
map<Point,int>num;
int maxnum = 0;
int getnum(Point P)
{
	if (num.find(P) != num.end())
	{
		return num[P];
	}
	num[P] = ++maxnum;
	return maxnum;
}
struct Edge 
{
	TriangleRef tri; 
	SideRef side; 
	Edge() : tri(0), side(0) {}
	Edge(TriangleRef tri, SideRef side) : tri(tri), side(side) {}
};
struct Triangle 
{
	Point p[3]; 
	Edge edge[3]; 
	TriangleRef children[3]; 
	Triangle(){}
	Triangle(Point const& p0, Point const& p1, Point const& p2) 
	{
		p[0]=p0;p[1]=p1;p[2]=p2;children[0]=children[1]=children[2]=0;
	}
	bool has_children() const { return children[0] != 0; }
	int num_children() const 
	{
		return children[0] == 0 ? 0
		: children[1] == 0 ? 1
		: children[2] == 0 ? 2 : 3;
	}
	bool contains(Point const& q) const 
	{
		ft a=side(p[0],p[1],q), b=side(p[1],p[2],q), c=side(p[2],p[0],q);
		return a >= -EPSILON && b >= -EPSILON && c >= -EPSILON;
	}
	Point Circumcenter()
	{
		ft x1,y1,x2,y2,x3,y3,A1,B1,C1,A2,B2,C2;
		x1 = p[0].x; y1 = p[0].y;
		x2 = p[1].x; y2 = p[1].y;
		x3 = p[2].x; y3 = p[2].y;
		A1 = 2*(x2-x1);
		B1 = 2*(y2-y1);
		C1 = x2*x2+y2*y2-x1*x1-y1*y1;
		A2 = 2*(x3-x2);
		B2 = 2*(y3-y2);
		C2 = x3*x3+y3*y3-x2*x2-y2*y2;
		ft x,y;
		x=((C1*B2)-(C2*B1))/((A1*B2)-(A2*B1));
        y=((A1*C2)-(A2*C1))/((A1*B2)-(A2*B1));
        return Point(x,y);
	}
} triangle_pool[MAX_TRIS], *tot_triangles;
void set_edge(Edge a, Edge b) 
{
	if (a.tri) a.tri->edge[a.side] = b;
	if (b.tri) b.tri->edge[b.side] = a;
}
class Triangulation {
public:
	Triangulation() 
	{
		const ft LOTS = 1e12;
		the_root = new(tot_triangles++) Triangle(Point(-LOTS,-LOTS),Point(+LOTS,-LOTS),Point(0,+LOTS));
	}
	TriangleRef find(Point p) const { return find(the_root,p);}
	void add_point(Point const& p) { add_point(find(the_root,p),p); }
private:
	TriangleRef the_root;
	static TriangleRef find(TriangleRef root, Point const& p) 
	{
		for( ; ; ) 
		{
			if (!root->has_children()) return root;
			else for (int i = 0; i < 3 && root->children[i] ;++i)
			if (root->children[i]->contains(p))
			{
				root = root->children[i]; 
				break;
			}
		}
	}
	void add_point(TriangleRef root, Point const& p) 
	{
		TriangleRef tab,tbc,tca;
		tab = new(tot_triangles++) Triangle(root->p[0], root->p[1], p);
		tbc = new(tot_triangles++) Triangle(root->p[1], root->p[2], p);
		tca = new(tot_triangles++) Triangle(root->p[2], root->p[0], p);
		set_edge(Edge(tab,0),Edge(tbc,1));set_edge(Edge(tbc,0),Edge(tca,1));
		set_edge(Edge(tca,0),Edge(tab,1));set_edge(Edge(tab,2),root->edge[2]);
		set_edge(Edge(tbc,2),root->edge[0]);set_edge(Edge(tca,2),root->edge[1]);
		root->children[0]=tab;root->children[1]=tbc;root->children[2]=tca;
		flip(tab,2); flip(tbc,2); flip(tca,2);
	}
	void flip(TriangleRef tri, SideRef pi) 
	{
		TriangleRef trj = tri->edge[pi].tri; int pj = tri->edge[pi].side;
		if(!trj||!in_circumcircle(tri->p[0],tri->p[1],tri->p[2],trj->p[pj])) return;
		TriangleRef trk = new(tot_triangles++) Triangle(tri->p[(pi+1)%3], trj->p[pj], tri->p[pi]);
		TriangleRef trl = new(tot_triangles++) Triangle(trj->p[(pj+1)%3], tri->p[pi], trj->p[pj]);
		set_edge(Edge(trk,0), Edge(trl,0));
		set_edge(Edge(trk,1), tri->edge[(pi+2)%3]); set_edge(Edge(trk,2), trj->edge[(pj+1)%3]);
		set_edge(Edge(trl,1), trj->edge[(pj+2)%3]); set_edge(Edge(trl,2), tri->edge[(pi+1)%3]);
		tri->children[0]=trk;tri->children[1]=trl;tri->children[2]=0;
		trj->children[0]=trk;trj->children[1]=trl;trj->children[2]=0;
		flip(trk,1); flip(trk,2); flip(trl,1); flip(trl,2);
	}
};
int n; 
Point ps[N];
ft Quo()
{
	LL v1,v2;
	scanf("%lld/%lld",&v1,&v2);
	return ft(1.0) * v1 / v2; 
}

vector<pair<int,ft> >e[100010];
void addedge(Point p1,Point p2)
{
	int num1 = getnum(p1);
	int num2 = getnum(p2);
	ft len = sqrt(dist_sqr(p1,p2));
	e[num1].push_back(make_pair(num2,len));
	e[num2].push_back(make_pair(num1,len));
}

int _=0;
ft d[100010];
bool inq[100010];
void solve()
{
	num.clear();
	maxnum = 0;
	tot_triangles = triangle_pool; 
	scanf("%d",&n);
	for (int i = 0; i < n; ++ i) 
	{
		double tx,ty;
		scanf("%lf%lf",&tx,&ty);
		ps[i].x = tx; ps[i].y = ty;
		//printf("%.3lf %.3lf\n",double(ps[i].x),double(ps[i].y));
	}
	random_shuffle(ps, ps + n); Triangulation tri;
	for (int i = 0; i < n; ++ i) tri.add_point(ps[i]);
	/*auto t = tri.find(Point(10.3,11.5));
	for (int i=0;i<3;i++)
	printf("%.3lf %.3lf\n",t->p[i].x,t->p[i].y);
	auto cc = t->Circumcenter();
	printf("%.3lf %.3lf\n",cc.x,cc.y);*/
	Point st,ed;
	ft R = Quo();
	st.x = Quo();st.y = Quo();
	ed.x = Quo();ed.y = Quo();
	//printf("%.3lf %.3lf %.3lf %.3lf %.3lf\n",R,st.x,st.y,ed.x,ed.y);
	printf("Case #%d: ",++_);
	for (int i=0;i<n;i++)
	{
		if (dist_sqr(st,ps[i]) < sqr(R) - eps2 || dist_sqr(ed,ps[i]) < sqr(R) - eps2)
		{
			puts("IMPOSSIBLE");
			return;
		}  
	}
	Triangle *tt;
	Point cc,midp;
	for (tt = triangle_pool;tt != tot_triangles;tt++)
	if (!tt->has_children())
	{
		cc = tt->Circumcenter();
		for (int i=0;i<3;i++)
		if (dist_sqr(tt->p[i],tt->p[(i+1)%3]) > 4 * R * R - 1e-6)
		{
			midp.x = (tt->p[i].x + tt->p[(i+1)%3].x) / 2;
			midp.y = (tt->p[i].y + tt->p[(i+1)%3].y) / 2;
			addedge(midp,cc);
		}
	}
	tt = tri.find(st);
	cc = tt->Circumcenter();
	addedge(st,cc);
	for (int i=0;i<3;i++)
	if (dist_sqr(tt->p[i],tt->p[(i+1)%3]) > 4 * R * R - 1e-6)
	{
		midp.x = (tt->p[i].x + tt->p[(i+1)%3].x) / 2;
		midp.y = (tt->p[i].y + tt->p[(i+1)%3].y) / 2;
		addedge(midp,st);
	}
	
	tt = tri.find(ed);
	cc = tt->Circumcenter();
	addedge(ed,cc);
	for (int i=0;i<3;i++)
	if (dist_sqr(tt->p[i],tt->p[(i+1)%3]) > 4 * R * R - 1e-6)
	{
		midp.x = (tt->p[i].x + tt->p[(i+1)%3].x) / 2;
		midp.y = (tt->p[i].y + tt->p[(i+1)%3].y) / 2;
		addedge(midp,ed);
	}
	for (auto pp:num)
	{
		printf("%.3lf %.3lf %d\n",pp.first.x,pp.first.y,pp.second);
	}
	int ST = getnum(st), ED = getnum(ed);
	queue<int>q;
	for (int i=1;i<=maxnum;i++)d[i] = INF,inq[i] = false;
	d[ST] = 0;
	q.push(ST);
	inq[ST] = true;
	while(!q.empty())
	{
		int now = q.front();
		for (auto t:e[now])
		if (d[now] + t.second < d[t.first])
		{
			d[t.first] = d[now] + t.second;
			if (!inq[t.first])
			{
				inq[t.first] = true;
				q.push(t.first);
			}	
		}	
		q.pop();
		inq[now] = false;
	}
	if (d[ED] == INF)
		puts("IMPOSSIBLE");
	else
		printf("%.3lf\n",double(d[ED]));
	for (int i=1;i<=maxnum;i++)e[i].clear();
}

int main()
{
	freopen("14_test3.in","r",stdin);
	//freopen("14_test.out","w",stdout); 
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
}
