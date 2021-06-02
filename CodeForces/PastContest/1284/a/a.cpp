#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N,M;
char s[100][100],t[100][100];

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++) {
        scanf("%s",s[i]);
    }
    for (int i=1;i<=M;i++) {
        scanf("%s",t[i]);
    }
    int Q,v;
    scanf("%d",&Q);
    while(Q--) {
        scanf("%d",&v);
        int v1 = v % N, v2 = v % M;
        if (v1 == 0) v1 = N;
        if (v2 == 0) v2 = M;
        printf("%s%s\n",s[v1],t[v2]);
    }
}