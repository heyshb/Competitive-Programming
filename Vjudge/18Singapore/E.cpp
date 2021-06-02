#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
class point {
public:
    LL x, y;
    point(){}
    point(LL _x, LL _y){x = _x; y = _y;}
    friend point operator - (point p1, point p2) {
        return point(p1.x - p2.x, p1.y - p2.y);
    };
    friend LL operator * (point p1, point p2) {
        return p1.x * p2.y - p1.y * p2.x;
    }
}p[5010];

LL area(point p1, point p2, point p3) {
    return abs((p3 - p1) * (p2 - p1));
}

int N;

int tp;
point stk[10010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%lld%lld",&p[i].x,&p[i].y);
    }
    sort(p+1, p+N+1, [](point p1, point p2) {
        if (p1.x == p2.x) return p1.y < p2.y;
        return p1.x < p2.x;
    });
    /*
    for (int i=1;i<=N;i++) {
        printf("%lld %lld\n",p[i].x, p[i].y);
    }
    */
    tp = 0;
    for (int i=1;i<=N;i++) {
        while(tp >= 2 && (p[i] - stk[tp - 1]) * (stk[tp] - stk[tp - 1]) >= 0) {
            tp--;
        }
        stk[++tp] = p[i];
    }
    int ntp = tp;
    for (int i=N-1;i>=1;i--) {
        while(tp > ntp && (p[i] - stk[tp - 1]) * (stk[tp] - stk[tp - 1]) >= 0) {
            tp--;
        }
        stk[++tp] = p[i];
    }
    /*
    for (int i=1;i<=tp;i++) {
        printf("%lld %lld\n",stk[i].x, stk[i].y);
    }
    */
    tp--;
    for (int i=1;i<=tp;i++) {
        stk[i + tp] = stk[i];
    }
    LL ans = 0;
    for (int i=1;i<=tp;i++) {
        int node = i;
        for (int j=i+1;j<=tp;j++) {
            node = max(node, j);
            while(node + 1 < i + tp && area(stk[i], stk[j], stk[node + 1]) >= area(stk[i], stk[j], stk[node])) {
                node++;
            }
            //printf("?? %lld\n",area(stk[i], stk[j], stk[node + 1]));
            //printf("%d %d %d\n",i,j,node);
            ans = max(ans, area(stk[i], stk[j], stk[node]));
        }
    }
    printf("%.10lf\n",ans * 0.5);
}