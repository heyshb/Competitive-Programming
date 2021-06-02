#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
vector<pii>e[210];
const int INF = 1e9;
bool done[210][2];
int d[210];
int maxdelta = -1;
int ansd[210];

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++) {
        int u, v, w;
        scanf("%d%d%d", &u,&v,&w);
        e[u].push_back(pii(v, w));
        e[v].push_back(pii(u, -w));
    }
    for (int s=1;s<=N;s++) {
        for (int i=1;i<=N;i++) {
            d[i] = INF;
        }
        d[s] = 0;
        for (int r=1;r<=N;r++) {
            for (int i=1;i<=N;i++) {
                for (auto t:e[i]) {
                    if (t.second == 0) {
                        d[t.first] = min(d[t.first], d[i] + 1);
                    } else {
                        d[t.first] = min(d[t.first], d[i] + t.second);
                    }
                }
            }
        }
        bool ok = true;
        for (int i=1;i<=N;i++) {
            if (d[i] < 0) ok = false; 
        }
        for (int i=1;i<=N;i++) {
            for (auto t:e[i]) {
                if (t.second == 0) {
                    if (abs(d[i] - d[t.first]) != 1) ok = false;
                } else {
                    if (d[t.first] - d[i] != t.second) ok = false;
                }
            }
        }
        if (ok) {
            int md = -1;
            for (int i=1;i<=N;i++) md = max(md, d[i]);
            if (md > maxdelta) {
                maxdelta = md;
                for (int i=1;i<=N;i++) {
                    ansd[i] = d[i];
                }
            }
        }
    }
    if (maxdelta == -1) {
        puts("NO");
    } else {
        puts("YES");
        printf("%d\n",maxdelta);
        for (int i=1;i<=N;i++) {
            printf("%d%c",ansd[i]," \n"[i==N]);
        }
    }
}