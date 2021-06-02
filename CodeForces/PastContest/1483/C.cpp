#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;

typedef long long LL;
int n, h[300010], b[300010];
LL f[300010], g[300010], gg[300010];
int top = 0;
int stk[300010];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&h[i]);
    }
    for (int i=1;i<=n;i++) {
        scanf("%d",&b[i]);
    }
    for (int i=1;i<=n;i++) {
        f[i] = -1e18;
        //printf("i = %d\n",i);
        LL mx = -1e18;
        while(top && h[stk[top]] > h[i]) {
            mx = max(mx, g[stk[top]]);
            top--;
        }
        mx = max(mx, f[i - 1]);
        g[i] = mx;
        f[i] = max(f[i], g[i] + b[i]);
        //printf("here f = %lld\n",f[i]);
        if (top) {
            f[i] = max(f[i], gg[top]);
        }
        stk[++top] = i;
        gg[top] = mx + b[i];
        if (top > 1) gg[top] = max(gg[top], gg[top - 1]);
        //printf("f[%d] = %lld\n",i,f[i]);
        //printf("g[%d] = %lld\n",i,g[i]);
        //printf("gg[%d] = %lld\n",i,gg[i]);
    }
    printf("%lld\n",f[n]);
}

/*
2
1 4
-3 4
*/