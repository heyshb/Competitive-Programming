#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;

vector<int> E[MAXN];
int p[MAXN], q[MAXN], r[MAXN];
int rm[MAXN];
int ans;
int vis[MAXN];

void dfs(int u, int fa){
	vis[u] = 1;
	vector<int> a;
	for (auto &v : E[u]){
		if (v != fa){
			if (!vis[v]){
				dfs(v, u);
				if (rm[v])
					a.push_back(v);
			}
			else
				if (v < u)
					a.push_back(v);
		}
	}
	for (int i = (a.size() % 2); i < a.size(); i += 2){
		ans++;
		p[ans] = a[i];
		q[ans] = u;
		r[ans] = a[i+1];
	}
	if (a.size() % 2 == 0){
		rm[u] = 1;
	}
	else{
		if (fa != 0){
			ans++;
			p[ans] = fa;
			q[ans] = u;
			r[ans] = a[0];
		}
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		sort(E[i].begin(), E[i].end());
	ans = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i]){
			dfs(i, 0);
		}
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++)
		printf("%d %d %d\n", p[i], q[i], r[i]);
	return 0; 
} 
