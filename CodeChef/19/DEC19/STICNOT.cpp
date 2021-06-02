#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int N,a[100010],b[100010],c[100010];

bool check(int x) {
    int M = 0;
    for (int i=x+1;i<=N;i++) {
        c[++M] = a[i];
    }
    for (int i=1;i<=x;i++) {
        c[++M] = INF;
    }
    for (int i=1;i<N;i++) {
        if (c[i] < b[i]) return false;
    }
    return true;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<N;i++) {
            int u,v;
            scanf("%d%d%d",&u,&v,&b[i]);
        }
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+N+1);
        sort(b+1,b+N);
        int L = 0, R = N;
        if (check(L)) {
            puts("0");
            continue;
        }
        while(L < R - 1) {
            int mid = (L + R) / 2;
            if (check(mid)) {
                R = mid;
            } else {
                L = mid;
            }
        }
        printf("%d\n",R);
    }
}