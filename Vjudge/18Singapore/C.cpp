#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int N;
int a[1000];

int main() {
    scanf("%d",&N);
    while(N--) {
        int u, v;
        scanf("%d%d",&u,&v);
        for (int i=u;i<=v;i++) a[i]++;
    }
    int ans = 0;
    for (int i=0;i<1000;i++) if (a[i] > 0) {
        ans++;
    }
    printf("%d\n",ans);
}