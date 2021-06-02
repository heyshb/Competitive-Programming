#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int>e[300010];

int main() {
    scanf("%d%d",&N,&K);
    for (int i=1;i<N;i++) {
        int u, v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
}