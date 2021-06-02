#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
pii p[52510];
pii pp[52510];

int getquad(pii p) {
    int X = p.first, Y = p.second;
    if (Y == 0) {
        if (X > 0) return 1;
        return 3;
    }
    if (X == 0) {
        if (Y > 0) return 2;
        return 4;
    }
    if (X > 0 && Y > 0) return 1;
    if (X < 0 && Y > 0) return 2;
    if (X < 0 && Y < 0) return 3;
    return 4;
}

LL mul(pii p1, pii p2) {
    return 1LL * p1.first * p2.second - 1LL * p1.second * p2.first;
}

bool cmp(pii p1, pii p2) {
    int q1 = getquad(p1), q2 = getquad(p2);
    if (q1 != q2) {
        return q1 < q2;
    }
    return mul(p1, p2) > 0;
}

LL C3(LL x) {
    return x * (x-1) * (x-2) / 6;
}

LL solve() {
    sort(pp+1,pp+M+1,cmp);
    for (int i=1;i<=M;i++) {
        pp[i+M] = pp[i];
    } 
    /*
    puts("solve");
    for (int i=1;i<=M;i++) {
        printf("%d %d\n",pp[i].first,pp[i].second);
    }
    */
    LL ret = 0;
    int j = 1;
    for (int i=1;i<=M;i++) {
        j = max(j, i);
        while(j + 1 < i + M && mul(pp[i], pp[j+1]) > 0) {
            j++;
        }
        //printf("j-i = %d\n",j-i);
        ret += C3(j - i);
    }
    //printf("ret = %lld\n",ret);
    return ret;
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d%d",&p[i].first,&p[i].second);
    }
    LL ans = 1LL * N * (N - 1) * (N - 2) * (N - 3) / 24;
    ans = ans * (N - 4);
    //printf("%lld\n",ans);
    for (int i=1;i<=N;i++) {
        M = 0;
        for (int j=1;j<=N;j++) {
            if (i == j) continue;
            pp[++M] = pii(p[j].first - p[i].first, p[j].second - p[i].second);
        }
        ans -= solve();
    }
    printf("%lld\n",ans);
}