#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int M = 1e9;
int query(int x, int y) {
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}

int main() {
    LL d1 = query(1, 1);
    LL d2 = query(M, 1);
    LL max_x1 = (M + d1 - d2 - 2) / 2;
    LL y1 = query(1 + max_x1, 1);
    LL y2 = query(1 + max_x1, M);
    LL x1 = d1 - y1;
    LL x2 = d2 - y1;
    printf("! %lld %lld %lld %lld\n",x1+1,y1+1,M-x2,M-y2);
    fflush(stdout);
}