#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, d[1010];
vector<int>e[1010];
bool del[1010];

void answer(int x) {
    printf("! %d\n",x);
    fflush(stdout);
    exit(0);
}

int ask(int u,int v) {
    printf("? %d %d\n",u,v);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<N;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        d[u]++;
        d[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue<int>q;
    for (int i=1;i<=N;i++) {
        if (d[i] == 1) {
            del[i] = true;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u,v;
        u = q.front();
        q.pop();
        if (q.empty()) {
            answer(u);
        }
        v = q.front();
        q.pop();
        int ret = ask(u, v);
        if (ret == u) {
            answer(u);
        }
        if (ret == v) {
            answer(v);
        }
        for (auto t:e[u]) {
            if (--d[t] <= 1 && !del[t]) {
                del[t] = true;
                q.push(t);
            }
        }
        for (auto t:e[v]) {
            if (--d[t] <= 1 && !del[t]) {
                del[t] = true;
                q.push(t);
            }
        }
    }
}