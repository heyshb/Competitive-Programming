#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, K;
int a[1000100];
int T[1000100];
int lowbit(int x) {
    return x & -x;
}
int getsum(int x) {
    int ret = 0;
    while(x) {
        ret += T[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x,int y) {
    while(x <= N) {
        T[x] += y;
        x += lowbit(x);
    }
}

int find(int pos) {
    int L = 0, R = N;
    while(L < R - 1) {
        int mid = (L + R) / 2;
        if (getsum(mid) >= pos) R = mid;
        else L = mid;
    }
    return R;
}

int solve(int len) {
    if (len > N) return -1;
    memset(T, 0, sizeof(T));
    for (int i=1;i<=len;i++) {
        add(a[i], 1);
    }
    int ret = find((len + 1) / 2);
    for (int i=len+1;i<=N;i++) {
        add(a[i], 1);
        add(a[i - len], -1);
        ret = max(ret, find((len + 1) / 2));
    }
    return ret;
}

int main() {
    scanf("%d%d",&N,&K);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    //printf("%d\n",solve(K));
    printf("%d\n",max(solve(K), solve(K + 1)));
}