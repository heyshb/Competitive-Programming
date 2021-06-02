#include <bits/stdc++.h>

using namespace std;

int T, N;
int fa[100010], d[100010], M;
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
vector<int>e[100010];
void addedge(int u, int v) {
    //printf("%d %d\n",u,v);
    e[u].push_back(v);
    e[v].push_back(u);
    d[u]++;d[v]++;
    M++;
}
typedef pair<int,int> pii;
vector<int>ans1;
vector<pii>ans2;
typedef long long LL;
LL S;
int p[100010];

void dfs(int x, int f) {
    ans1.push_back(x);
    for (auto &t:e[x]) {
        if (t == f) continue;
        S += 1LL * (t - x) * (t - x);
        dfs(t, x);
        ans2.push_back(pii(t, x));
    }
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            e[i].clear();
            fa[i] = i;
            d[i] = 0;
        }
        M = 0;
        addedge(1, N);
        for (int Len=N-2;Len;Len--) {
            addedge(1, 1 + Len);
            if (M == N - 1) break;
            addedge(N, N - Len);
            if (M == N - 1) break;
        }
        ans1.clear();
        ans2.clear();
        S = 0;
        dfs(1, 0);
        printf("%lld\n",S);
        for (int i=0;i<N-1;i++) p[ans1[i]] = ans1[i + 1];
        p[ans1[N - 1]] = ans1[0];
        for (int i=1;i<=N;i++) printf("%d%c",p[i]," \n"[i==N]);
        printf("%d\n",ans2.size());
        for (auto &t:ans2) printf("%d %d\n",t.first,t.second);
        /* 
           int calc = 0;
        int E = 0;
        for (int Len=N-1;Len>=1;Len--) {
            int lencnt = 0;
            for (int i=1;i+Len<=N;i++) {
                //printf("%d %d\n",Len,i);
                int R = i + Len;
                if (find(i) == find(R)) continue;
                lencnt++;
                e[i].push_back(R);
                e[R].push_back(i);
                printf("add %d %d\n",i,R);
                fa[find(i)] = find(R);
                if (++E == N - 1) break;
            }
            if (E == N - 1) break;
            printf("%d %d\n",Len,lencnt);
        }
        printf("%d %d\n",E,calc);
        */
    }
}