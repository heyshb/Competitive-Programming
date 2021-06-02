#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N, M;
int a[100010];
LL sum[100010];
set<LL>s;

void build(int L,int R) {
    //printf("build %d %d %lld\n",L,R,sum[R] - sum[L-1]);
    if (L > R) return;
    s.insert(sum[R] - sum[L - 1]);
    if (a[L] == a[R]) return;
    int mid = (a[L] + a[R]) / 2;
    int id = upper_bound(a+1,a+N+1,mid) - a;
    build(L,id-1);
    build(id,R);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        sum[0] = 0;
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        s.clear();
        sort(a+1,a+N+1);
        for (int i=1;i<=N;i++)sum[i] = sum[i - 1] + a[i];
        build(1,N);
        while(M--) {
            int tmp;
            scanf("%d",&tmp);
            if (s.find(tmp) != s.end()) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
}