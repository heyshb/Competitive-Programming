#include <bits/stdc++.h>

using namespace std;

int N, a[50010];
vector<int>e[50010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<N;i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
}