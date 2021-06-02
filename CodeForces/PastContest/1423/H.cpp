#include <bits/stdc++.h>

#define ls (rt << 1)
#define rs (ls | 1)
#define mid ((l + r) >> 1)
using namespace std;
const int maxn = 1e6, maxm = 1 << 21;
int n, m, o[maxn + 3], u[maxn + 3], v[maxn + 3], fa[maxn + 3], sz[maxn + 3];
int top, st_u[maxn + 3], st_v[maxn + 3], st_o[maxn + 3], st_s[maxn + 3];
int ans[maxn + 3];
vector<int> S[maxm + 3];
map<pair<int, int>, int> mp, erase_cnt;
void modify(int rt, int l, int r, int lx, int rx, int x) {
	if (l >= lx && r <= rx) {
		S[rt].push_back(x);
		return;
	}
	if (lx <= mid) {
		modify(ls, l, mid, lx, rx, x);
	}
	if (rx > mid) {
		modify(rs, mid + 1, r, lx, rx, x);
	}
}
int find(int x) {
	return fa[x] == x ? x : find(fa[x]);
}
void merge(int u, int v) {
	u = find(u), v = find(v);
	if (sz[u] > sz[v]) {
		swap(u, v);
	}
	++top, st_u[top] = u, st_v[top] = v, st_o[top] = fa[u], st_s[top] = sz[u];
	if (u != v) {
		fa[u] = v, sz[v] += sz[u], sz[u] = 0;
	}
}
void split() {
	int u = st_u[top], v = st_v[top], o = st_o[top], s = st_s[top];
	if (u != v) {
		fa[u] = o, sz[v] -= s, sz[u] = s;
	}
	top--;
}
void insert(int x) {
	for (int i = 0; i < S[x].size(); i++) {
		merge(u[S[x][i]], v[S[x][i]]);
	}
}
void erase(int x) {
	for (int i = S[x].size() - 1; i >= 0; i--) {
		split();
	}
}
void solve(int rt, int l, int r) {
	insert(rt);
	if (l == r) {
		if (o[l] == 2) {
			ans[l] = sz[find(u[l])];
		}
		erase(rt);
		return;
	}
	solve(ls, l, mid);
	solve(rs, mid + 1, r);
	erase(rt);
}
typedef pair<int,int> pii;
vector<pii>op[1000010];
int U[1000010], V[1000010], O[1000010];
int M = 0;

int main() {
    int K;
	scanf("%d%d%d", &n, &m, &K);
    int day = 1;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &O[i]);
        if (O[i] <= 2) scanf("%d", &U[i]);
        if (O[i] <= 1) scanf("%d", &V[i]);
		if (O[i] == 1) {
            if (U[i] > V[i]) {
                swap(U[i], V[i]);
            }
            op[day].push_back(pii(0,i));
            op[day + K].push_back(pii(1,i));
		} else if (O[i] == 2) {
            op[day].push_back(pii(2,i));
		} else {
            day++;
        }
	}
    for (int i=1;i<=day;i++) {
        for (auto t:op[i]) {
            M++;
            o[M] = t.first;
            u[M] = U[t.second];
            v[M] = V[t.second];
        }
    }
    m = M;
    for (int i = 1; i <= m; i++) {
        //printf("%d %d %d\n",o[i],u[i],v[i]);
		if (!o[i]) {
            if (mp[make_pair(u[i], v[i])] == 0) {
			    mp[make_pair(u[i], v[i])] = i;
            }
            erase_cnt[make_pair(u[i], v[i])] += 1;
		} else if (o[i] == 1) {
            //printf("add %d---%d %d %d\n",mp[make_pair(u[i], v[i])], i - 1, u[i], v[i]);
            if (--erase_cnt[make_pair(u[i], v[i])] == 0) {
			    modify(1, 1, m, mp[make_pair(u[i], v[i])], i - 1, i);
    			mp[make_pair(u[i], v[i])] = 0;
            }
		}
	}
	for (map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it -> second) {
			modify(1, 1, m, it -> second, m, it -> second);
		}
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i, sz[i] = 1;
	}
	solve(1, 1, m);
	for (int i = 1; i <= m; i++) {
		if (o[i] == 2) {
            printf("%d\n",ans[i]);
		}
	}
	return 0;
}