#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int a,b,c,d,x,y,x1,x2,y1,y2;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);
        bool ok = true;
        if ((x + b - a) > x2 || (x + b - a) < x1) ok = false;
        if ((y + d - c) > y2 || (y + d - c) < y1) ok = false;
        if ((x1 == x2) && (a > 0 || b > 0)) ok = false;
        if ((y1 == y2) && (c > 0 || d > 0)) ok = false;
        puts(ok ? "Yes" : "No");
    }
}