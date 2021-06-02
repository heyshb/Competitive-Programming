#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MAXN = 550010;
int L1[MAXN],R1[MAXN],L2[MAXN],R2[MAXN];
int N;
vector<pii>ans,e1[MAXN];
int d1[MAXN],d2[MAXN];
bool er2[MAXN],er1[MAXN];
int head[MAXN];
pii e2[MAXN];
int nxt[MAXN];
int M = 0;

void addedge(int u,int v,int i) {
    M++;
    e2[M] = pii(v, i);
    nxt[M] = head[u];
    head[u] = M;
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<N;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        L1[i] = u;
        L2[i] = v;
        e1[u].push_back(pii(v,i));
        e1[v].push_back(pii(u,i));
        d1[u]++;
        d1[v]++;
    }
    for (int i=1;i<N;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        L2[i] = u;
        R2[i] = v;
        d2[u]++;
        d2[v]++;
        addedge(u,v,i);
        addedge(v,u,i);
    }
    queue<int>q1,q2;
    for (int i=1;i<=N;i++) {
        if (d1[i] == 1) {
            q2.push_back(i);
            if (d2[i] == 1) {
                q1.push_back(i);
            }
        }
    }
    while(!(q1.empty() && q2.empty())) {
        while(!q1.empty()) {
            int now = q1.front();
            q1.pop();
            for (auto t:e1[now]) {
                if (!er1[t.second]) {
                    er1[t.second] = true;
                    int d1n = t.first;
                    pii nans;
                    nans.first = t.second;
                    for (int i=head[now];i;i=nxt[i]) {
                        if (!er2[e2[i].second]) {
                            er2[e2[i].second] = true;
                            break;
                        } 
                    }
                    ans.push_back(nans);
                    break;
                }
            }
        }
    }
    printf("%d\n",N-1);
    for (auto t:ans) {
        printf("%d %d %d %d\n",L1[t.first],R1[t.first],L2[t.second],R2[t.second]);
    }
}