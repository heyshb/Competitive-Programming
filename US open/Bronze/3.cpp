#include <bits/stdc++.h>

using namespace std;

map<string,int>num;
int md = 10;
int N,cnt=0;
int fa[1010],d[1010];
int mo[1010];
vector<int>e[1010];

int find(int x)
{
	return x==mo[x]?x:mo[x]=find(mo[x]);
}

string tmp;
int getnum()
{	
	cin >> tmp;
	if (num.find(tmp) != num.end()) return num[tmp];
	cnt++;
	num[tmp] = cnt;
	return cnt;
}

void dfs(int x)
{
	d[x] = d[fa[x]] + 1;
	for (auto t:e[x])
		dfs(t);
}

string namex,namey;

int main()
{
	freopen("family.in","r",stdin);
	freopen("family.out","w",stdout);
	scanf("%d",&N);
	int X,Y;
	X = getnum();
	namex = tmp;
	Y = getnum();
	namey = tmp;
	//printf("%d %d\n",X,Y);
	for (int i=1;i<=2*N+2;i++)mo[i] = i;
	for (int i=1;i<=N;i++)
	{
		int u,v;
		u = getnum();
		v = getnum();
		mo[find(u)] = find(v);
		fa[v] = u;
		//printf("fa[%d]=%d\n",v,u);
		e[u].push_back(v);
	}
	for (int i=1;i<=cnt;i++)
	if (fa[i] == 0) dfs(i);
	//printf("%d %d\n",d[X],d[Y]);
	if (find(X) != find(Y)) return 0 * puts("NOT RELATED");
	if (fa[X] == fa[Y]) return 0 * puts("SIBLINGS");
	if (d[X] < d[Y])
	{
		swap(namex,namey);
		swap(X,Y);
	}
	if (fa[X] == Y)
	{
		cout << namey << " is the mother of " << namex << endl;
		return 0;
	}
	int XX = X, YY = Y;
	while(d[XX] > d[YY]) XX = fa[XX];
	while(XX != 0 && XX != YY) 
	{
		XX = fa[XX];
		YY = fa[YY];
	}
	assert(XX);
	int lca = XX;
	if (lca == Y)
	{
		cout << namey << " is the ";
		for (int i=1;i<=d[X] - d[Y] - 2;i++)cout<<"great-";
		cout << "grand-mother of " << namex << endl;
		return 0;
	}
	
	if (fa[Y] == lca)
	{
		cout << namey << " is the ";
		for (int i=1;i<=d[X] - d[Y] - 1;i++)cout<<"great-";
		cout<<"aunt of "<< namex << endl;
		return 0;
	}
	
	cout << "COUSINS" << endl;
}
