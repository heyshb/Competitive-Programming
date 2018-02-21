#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
vector<int>e[100010],e2[100010];
vector<pair<int,LL> >op[100010];
int fa[100010],hson[100010],size[100010],nxt[100010],root[100010];
int pos[100010],length[100010]; 
bool vis[100010];
LL w[100010],ans[100010];
const LL INF = 1e15;

void dfs(int x)
{
	size[x] = 1;
	int maxsize = 0;
	hson[x] = 0;
	for (auto t:e[x])
	{
		dfs(t);
		size[x] += size[t];
		if (size[t] > maxsize)
		{
			hson[x] = t;
			maxsize = size[t];
		}
	}
}

int cnt,num[1000010];

struct Node
{
	LL mi,flag;
	int ls,rs;
}T[1000010];

void setflag(int x,LL f)
{
	if (x)
	{
		T[x].flag += f;
		T[x].mi += f;
	}
}


void pushdown(int x)
{
	if (T[x].flag)
	{
		setflag(T[x].ls,T[x].flag);
		setflag(T[x].rs,T[x].flag);
		T[x].flag = 0;
	}
}

int firstsm(int x,int l,int r,int ql,int qr,LL WW)
{
	//printf("FSM %d %d %d %d %d %lld %lld\n",x,l,r,ql,qr,WW,T[x].mi);
	int mid = (l+r)>>1;
	pushdown(x);
	if (l == ql && r == qr)
	{
		if (T[x].mi < WW)
		{
			if (l == r) 
			{
				//printf("RETURN NUM[X] = %d\n",num[x]);
				return num[x];
			}
			if (T[T[x].rs].mi < WW)
				return firstsm(T[x].rs,mid+1,r,mid+1,r,WW);
			else	
				return firstsm(T[x].ls,l,mid,l,mid,WW);
		}
		else return -1;
	}
	if (qr <= mid)
		return firstsm(T[x].ls,l,mid,ql,qr,WW);
	else if (ql > mid)
		return firstsm(T[x].rs,mid+1,r,ql,qr,WW);
	else
	{
		LL resr = firstsm(T[x].rs,mid+1,r,mid+1,qr,WW);
		if (resr != -1) return resr;
		return firstsm(T[x].ls,l,mid,ql,mid,WW);
	}
}

LL getnum(int x,int l,int r,int p)
{
	pushdown(x);
	if (l == r) return T[x].mi;
	int mid = (l+r)>>1;
	if (p<=mid)
		return getnum(T[x].ls,l,mid,p);
	else
		return getnum(T[x].rs,mid+1,r,p);
}

void add(int x,int l,int r,int ql,int qr,LL delta)
{
	pushdown(x);
	if (l == ql && r == qr)
	{
		setflag(x,delta);
		return;
	}
	int mid = (l+r)>>1;
	if (qr <= mid)
		add(T[x].ls,l,mid,ql,qr,delta);
	else if (ql > mid)
		add(T[x].rs,mid+1,r,ql,qr,delta);
	else
	{
		add(T[x].ls,l,mid,ql,mid,delta);
		add(T[x].rs,mid+1,r,mid+1,qr,delta);
	}
	T[x].mi = min(T[T[x].ls].mi,T[T[x].rs].mi);
}

LL nv;
int grow(int x,LL delta)
{
	nv = INF;
	printf("Grow %d %lld\n",x,delta);
	int res = -1,tmp = x;
	while(tmp)
	{
		res = firstsm(root[tmp],1,length[tmp],1,pos[tmp],delta);
		if (res != -1) break;
		tmp = nxt[tmp];
	}
	printf("Res = %d\n",res);
	if (res == -1)
	{
		tmp = x;
		while(tmp)
		{
			printf("ADD %d %lld\n",tmp,-delta);
			add(root[tmp],1,length[tmp],1,pos[tmp],-delta);
			tmp = nxt[tmp];
		}
	}
	else
	{
		tmp = res;
		LL nowv = w[res] - getnum(root[res],1,length[res],pos[res]);
		//printf("GENUM %d = %lld\n",res,nowv);
		nv = nowv;
		while(tmp)
		{
			printf("ADD %d %lld\n",tmp,nowv);
			add(root[tmp],1,length[tmp],1,pos[tmp],nowv);
			tmp = nxt[tmp];
		}
	}
	return res;
}

int chain[100010],chainlen;

int build(int l,int r)
{
	int now = ++cnt;
	T[now].flag = 0;
	if (l == r)
	{
		num[now] = chain[l];
		T[now].ls = T[now].rs = 0;
		T[now].mi = w[chain[l]];
		num[chain[l]] = now;
		return now;
	}
	int mid = (l+r)>>1;
	int LS = build(l,mid), RS = build(mid+1,r);
	T[now].ls = LS;
	T[now].rs = RS;
	T[now].mi = min(T[LS].mi,T[RS].mi);
	return now;
}

LL total;

void solve(int x)
{
	printf("Solveing %d\n",x);
	LL rev;
	for (int i=0;i<e2[x].size();i++)
	{
		auto t = op[x][i];
		printf("To %d!\n",e2[x][i]);
		if (t.second == -1)
		{
			LL nowsum = w[t.first] - getnum(root[t.first],1,length[t.first],pos[t.first]);
			printf("%d,%lld Nowsum = %lld\n",t.first,t.second,nowsum);
			assert(nowsum >= 0);
			grow(t.first,-nowsum);
			ans[e2[x][i]] = nowsum;
			solve(e2[x][i]);
			grow(t.first,nowsum);
			//printf("%lld\n",nowsum);
		}
		else
		{
			ans[e2[x][i]] = grow(t.first,t.second) - 1;
			if (nv != INF)
				rev = -nv;
			else
				rev = -t.second;
			printf("First fall = %lld\n",ans[e2[x][i]]);
			solve(e2[x][i]);
			grow(t.first,rev);
		}
	}
	printf("Solving %d Over\n",x);
}

int main()
{
	int Cases,Q;
	scanf("%d",&Cases);
	while(Cases--)
	{
		scanf("%d%d",&N,&Q);
		for (int i=1;i<=N+1;i++)e[i].clear();
		for (int i=2;i<=N+1;i++)
		{
			scanf("%d%lld",&fa[i],&w[i]);
			fa[i]++;
			printf("%d--->%d %lld\n",fa[i],i,w[i]);
			e[fa[i]].push_back(i);
		}
		fa[1] = 0;
		N++;
		w[1] = INF;
		dfs(1);
		cnt = 0;
		for (int i=1;i<=N;i++)
		if (i != hson[fa[i]])
		{
			chainlen = 0;
			for (int j=i;j;j=hson[j])
			{
				chain[++chainlen] = j;
			}
			int tmp = build(1,chainlen);
			for (int j=1;j<=chainlen;j++)
			{
				root[chain[j]] = tmp;
				nxt[chain[j]] = fa[i];
				pos[chain[j]] = j;
				length[chain[j]] = chainlen;
			}
		}
		
		//for (int i=1;i<=N;i++)printf("%d %d\n",nxt[i],pos[i]);
		
		int state,type;
		for (int _=1;_<=Q;_++)
		{
			int u;
			LL x;
			scanf("%d%d",&state,&type);
			e2[state].push_back(_);
			//printf("%d -- > %d\n",state,_);
			if (type == 1)
			{
				scanf("%d%lld",&u,&x);
				u++;
				op[state].push_back(make_pair(u,x));
			}
			else
			{
				scanf("%d",&u);
				u++;
				op[state].push_back(make_pair(u,-1));
			}
		}
		total = 0;
		solve(0);
		for (int i=1;i<=Q;i++)
			if (ans[i] < 0)
				puts("0");
			else
				printf("%lld\n",ans[i]);
	}
}

/*

1
5 6
0 5
1 3
0 2
3 1
3 4
0 1 5 5
0 1 4 1
2 1 5 2
2 2 3
4 1 5 2
3 1 1 7



5
0
3
1
0
1

*/
