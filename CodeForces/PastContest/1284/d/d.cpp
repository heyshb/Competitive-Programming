#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MAXN = 100010;
pii v1[MAXN], v2[MAXN];
int N, M;
pii e[MAXN * 2];
multiset<int> l,r;

void solve() {
    M = 0;
    for (int i=1;i<=N;i++) {
        e[++M] = pii(v1[i].X, i); 
        e[++M] = pii(v1[i].Y + 1, -i); //erase
    }
    sort(e+1,e+M+1);
    l.clear();
    r.clear();
    int node = 1;
    while(node <= M) {
        int rnode = node;
        while(rnode < M && e[rnode+1].X == e[node].X) {
            rnode++;
        }
        for (int i=node;i<=rnode;i++) {
            int t = abs(e[i].Y);
            int tl = v2[t].X;
            int tr = v2[t].Y;
            if (e[i].Y > 0) {
                l.insert(tl);
                r.insert(tr);
            } else {
                l.erase(l.find(tl));
                r.erase(r.find(tr));
            }
        }
        if (!l.empty()) {
            int minR = (*r.begin());
            int maxL = (*l.rbegin());
            if (minR < maxL) {
                puts("NO");
                exit(0);
            }
        }
        node = rnode + 1;
    }
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d%d%d%d",&v1[i].X,&v1[i].Y,&v2[i].X,&v2[i].Y);
    }
    solve();
    for (int i=1;i<=N;i++) {
        swap(v1[i],v2[i]);
    }
    solve();
    puts("YES");
}